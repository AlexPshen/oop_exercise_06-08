#ifndef UNTITLED_POINT_H
#define UNTITLED_POINT_H

#include <iostream>

typedef struct{
    double x, y;
}point;

double scalar_mult(point top1_end, point top_begin, point top2_end);
double segment_length(point top1, point top2);

#endif //UNTITLED_POINT_H
