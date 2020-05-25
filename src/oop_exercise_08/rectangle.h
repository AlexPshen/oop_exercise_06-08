#ifndef UNTITLED_RECTANGLE_H
#define UNTITLED_RECTANGLE_H

#include "figure.h"

struct rectangle : public fig{
private:
    point top1, top2, top3, top4;
public:
    rectangle(std::istream& is){
        is >> top1.x >> top1.y >> top2.x >> top2.y >> top3.x >> top3.y >> top4.x >> top4.y;
        double scalar1 = scalar_mult(top2, top1, top3);
        double scalar2 = scalar_mult(top2, top1, top4);
        double scalar3 = scalar_mult(top3, top1, top4);
        double scalar01, scalar02, scalar03;
        if(scalar1 == 0){
            scalar01 = scalar_mult(top4, top2, top1);
            scalar02 = scalar_mult(top2, top4, top3);
            scalar03 = scalar_mult(top1, top3, top4);
            if(!(scalar01 == 0 && scalar02 == 0 && scalar03 == 0)){
                throw std::logic_error("It is not rectangle");
            }
        } else if(scalar2 == 0){
            scalar01 = scalar_mult(top1, top2, top3);
            scalar02 = scalar_mult(top1, top4, top3);
            scalar03 = scalar_mult(top2, top3, top4);
            if(!(scalar01 == 0 && scalar02 == 0 && scalar03 == 0)){
                throw std::logic_error("It is not rectangle");
            }
        } else if(scalar3 == 0){
            scalar01 = scalar_mult(top3, top2, top4);
            scalar02 = scalar_mult(top1, top4, top2);
            scalar03 = scalar_mult(top2, top3, top1);
            if(!(scalar01 == 0 && scalar02 == 0 && scalar03 == 0)){
                throw std::logic_error("It is not rectangle");
            }
        } else {
            throw std::logic_error("It is not rectangle");
        }
    }

    bool correct() const override;
    point center() const override;
    double square() const override;
    void print(std::ostream& os) const override;
};

#endif //UNTITLED_RECTANGLE_H
