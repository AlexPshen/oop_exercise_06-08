#include<iostream>
#include<vector>
#include<cmath>
#include<string.h>

#include "trigon.h"
#include "figure.h"

bool trigon::correct() const{
    if((top.x - l.x) * (r.y - l.y) == (top.y - l.y) * (r.x - l.x)){
        return false;
    }
    return true;
}

double trigon::square() const{
    double mult1 = (r.x - l.x) * (top.y - l.y);
    double mult2 = (top.x - l.x) * (r.y - l.y);
    return 0.5 * fabs(mult1 - mult2);
}


point trigon::center() const{
    double mid1 = (r.x + l.x + top.x) / 3;
    double mid2 = (r.y + l.y + top.y) / 3;
    return point{mid1, mid2};
}

void trigon::print(std::ostream& os) const{
    os << "trigon: ";
    os << "(" << l.x << ", " << l.y << ")" << " ";
    os << "(" << r.x << ", " << r.y << ")" << " ";
    os << "(" << top.x << ", " << top.y << ")" << '\n';
}

