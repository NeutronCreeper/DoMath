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
#ifndef _PI
#define _PI ((double)3.14159265359)
#endif
#ifndef _PI_r
#define _PI_r (to_ratiof(_PI))
#endif

class circle_r{
    private:
    point_r O;
    ratio r;
    public:
    void operator=(const circle_r& o){
        O=o.O;
        r=o.r;
    };
    bool operator==(const circle_r& o){
        if((O==o.O)&&(r==o.r)) return true;
        return false;
    };
    ratio circumference(){
        ratio ans;
        ans=r;
        ans.mul(2);
        ans*=_PI_r;
        return ans;
    };
    ratio area(){
        return r*r*_PI_r;
    };
}; 