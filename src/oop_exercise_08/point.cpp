#include<iostream>
#include<vector>
#include<cmath>
#include<string.h>


#include "point.h"

double scalar_mult(point top1_end, point top_begin, point top2_end){
    return (top_begin.x - top1_end.x)*(top_begin.x - top2_end.x) + (top_begin.y - top1_end.y)*(top_begin.y - top2_end.y);
}

double segment_length(point top1, point top2){
    return sqrt(pow(top1.x - top2.x, 2) + pow(top1.y - top2.y, 2));
}