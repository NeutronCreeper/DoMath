#define CIRCLE

#ifndef iostream
#include<iostream>
#endif
#ifndef RECTCOORD
#include "rectcoord.h"
#endif
#ifndef _PI
#define _PI ((double)3.14159265359)
#endif

//circle:point O;float r;
class circle{
    private:
    point O;
    float r=1;
    public:
    void operator=(const circle& o){
        O=o.O;
        r=o.r;
    };
    bool operator==(const circle& o){
        if((O==o.O)&&(r==o.r)) return true;
        return false;
    };
    float circumference(){
        return 2*r*_PI;
    };
    float area(){
        return _PI*r*r;
    };
};