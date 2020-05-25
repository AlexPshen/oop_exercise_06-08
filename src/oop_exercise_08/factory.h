#ifndef UNTITLED_FACTORY_H
#define UNTITLED_FACTORY_H

#include <memory>
#include <iostream>
#include <fstream>
#include "trigon.h"
#include "rectangle.h"
#include "quadrate.h"
#include <string>

struct factory {
    std::shared_ptr<fig> fig_create(std::istream& is);
    std::shared_ptr<fig> fig_create_file(std::ifstream& is);

};


#endif //UNTITLED_FACTORY_H
