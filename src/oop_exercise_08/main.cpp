#include <iostream>
#include <memory>
#include <vector>
#include <condition_variable>
#include <thread>
#include <mutex>
#include "factory.h"
#include "figure.h"
#include "trigon.h"
#include "rectangle.h"
#include "quadrate.h"

struct processor {
    virtual void process(std::shared_ptr<std::vector<std::shared_ptr<fig>>> buffer) = 0;

};

struct stream_processor : processor {
    void process(std::shared_ptr<std::vector<std::shared_ptr<fig>>> buffer) override{
        for (const auto& figure : *buffer) {
            figure -> print(std::cout);
        }
    }
};

struct file_processor : processor {
    void process(std::shared_ptr<std::vector<std::shared_ptr<fig>>> buffer) override{
        std::ofstream fout;
        fout.open(std::to_string(counter) + ".txt");
        ++counter;
        if (!fout.is_open()) {
            std::cout << "File not opened\n";
            return;
        }
        for (const auto& figure : *buffer) {
            figure -> print(fout);
        }

    }
private:
    int counter = 0;
};

struct executor {
    void operator()(){
        while(1) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock,[&]{ return (buffer != nullptr || flag);});
            if (flag) {
                break;
            }
            for (const auto& elem: processors) {
                elem->process(buffer);
            }
            buffer = nullptr;
            cv.notify_all();
        }
    }

    std::mutex& get_mtx(){
        return mtx;
    }

    void push_buf(std::shared_ptr<std::vector<std::shared_ptr<fig>>> buf){
         buffer = buf;
    }

    std::shared_ptr<std::vector<std::shared_ptr<fig>>> get_buf(){
        return buffer;
    }

    bool empty_buf(){
        return buffer == nullptr;
    }

    void notify_all(){
        cv.notify_all();
    }

    void flag_true(){
        flag = true;
    }

    std::vector<std::shared_ptr<processor>> processors;
    std::shared_ptr<std::vector<std::shared_ptr<fig>>> buffer;
    std::mutex mtx;
    std::condition_variable cv;
    bool flag = false;

};



int main(int argc,char* argv[]) {
    if (argc != 2) {
        std::cout << "ERROR";
        return 1;
    }
    int buffer_size = std::stoi(argv[1]);
    std::shared_ptr<std::vector<std::shared_ptr<fig>>> buffer;
    buffer = std::make_shared<std::vector<std::shared_ptr<fig>>>();
    buffer -> reserve(buffer_size);
    factory fact;
    executor sub;
    sub.processors.push_back(std::make_shared<stream_processor>());
    sub.processors.push_back(std::make_shared<file_processor>());
    std::thread sthread(std::ref(sub));

    while(1) {
        std::string comm;
        std::unique_lock<std::mutex> mut(sub.get_mtx());
        std::cin >> comm;
        if (comm == "add") {
            std::shared_ptr<fig> fig = fact.fig_create(std::cin);
            if(fig == nullptr){
                continue;
            }
            buffer -> push_back(fig);
            if (buffer -> size() == buffer_size) {
                sub.push_buf(buffer);
                sub.notify_all();
                sub.cv.wait(mut, [&](){ return sub.empty_buf();});
                buffer -> clear();
            }
        } else if (comm == "exit"){
            break;
        } else {
            std::cout << "unknown command\n";
        }
    }

    sub.flag_true();
    sub.notify_all();
    sthread.join();


    return 0;
}
