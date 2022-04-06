#define REAL

#ifndef iostream
#include<iostream>
#endif
#ifndef STRUCTURE
#include "structure.h"
#endif
#ifndef RATIO
#include "ratio.h"
#endif

class real_single{
    private:
    ratio a,b=to_ratio(1);
    public:
    void set(ratio& x,ratio& y){
        a=x;
        b=y;
    };
    void print(){
        std::cout<<'['<<a.expression()<<'^'<<b.expression()<<']';
    };
    void operator=(const real_single& x){
        a=x.a;
        b=x.b;
    };
    friend real_single real_single_create(const ratio& x,const ratio& y);
    //
};
real_single real_single_create(const ratio& x,const ratio& y){
    real_single ans;
    ans.a=x;
    ans.b=y;
    return ans;
};
real_single sqrt_r(const ratio& m){
    return real_single_create(m,ratio_create(1,2));
};