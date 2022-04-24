#define CIRCLE

#ifndef iostream
#include<iostream>
#endif
#ifndef RECTCOORD
#include "rectcoord.h"
#endif
#ifndef PI_
#define PI_ ((double)3.14159265359)
#endif

template<typename num>class circle{
    private:
    point<num> O;
    num r;
    public:
    circle(const point<num>& O_,const num& r_){
        O=O_;
        r=r_;
    };
    void operator()(const point<num>& O_,const num& r_){
        O=O_;
        r=r_;
    };
    void operator=(const circle<num>& circle_){
        O=circle_.O;
        r=circle_.r;
    };
    void operator==(const circle<num>& circle_){
        return (O==circle_.O)&&(r==circle_.r);
    };
};