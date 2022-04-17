#define CIRCLE_RATIO

#ifndef iostream
#include<iostream>
#endif
#ifndef RATIO
#include "ratio.h"
#endif
#ifndef RECTCOORD_RATIO
#include "rectcoord_r.h"
#endif
#ifndef PI_
#define PI_ ((double)3.14159265359)
#endif
#ifndef PI_r
#define PI_r (to_ratiof(PI_))
#endif

class circle_r{
    private:
    point_r O;
    ratio r;
    public:
    inline circle_r(ratio _O=ratio(),ratio _r=ratio(1,1)){
        O=_O;
        r=_r;
    };
    void operator=(const circle_r& o){
        O=o.O;
        r=o.r;
    };
    bool operator==(const circle_r& o){
        if((O==o.O)&&(r==o.r)) return true;
        return false;
    };
    ratio circumference(){
        return mul(r,2);
    };
    ratio area(){
        return r*r;
    };
}; 