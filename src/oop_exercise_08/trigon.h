#ifndef UNTITLED_TRIGON_H
#define UNTITLED_TRIGON_H

#include <iostream>
#include "figure.h"

struct trigon : public fig{
private:
    point l, r, top;
public:
    trigon(std::istream& is){
        is >> l.x >> l.y >> r.x >> r.y >> top.x >> top.y;
        if((top.x - l.x) * (r.y - l.y) == (top.y - l.y) * (r.x - l.x)){
            throw std::logic_error("It is not trigon");
        }
    }

    bool correct() const override;
    point center() const override;
    double square() const override;
    void print(std::ostream& os) const override;
};

#endif //UNTITLED_TRIGON_H
