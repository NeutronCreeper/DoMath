#define PARABOLA_RATIO

#ifndef iostream
#include<iostream>
#endif
#ifndef RATIO
#include "ratio.h"
#endif
#ifndef RECTCOORD_RATIO
#include "rectcoord_r.h"
#endif
#ifndef REAL
#include "real.h"
#endif

class parabola_r{
    private:
    ratio a,b,c;
    public:
    parabola_r(ratio x=ratio(1,1),ratio y=ratio(),ratio z=ratio()){
        a=x;
        b=y;
        c=z;
    };
    void set(ratio p,ratio q,ratio r,bool akm=0){
        if(akm){
            r+=(p*q*q-mul(p*r,4));
            q*=mul(p,2);;
        }
        a=p;
        b=q;
        c=r;
    };
    friend ostream& operator<<(ostream& output,const parabola_r p){
        output<<"parabola:y="<<p.a<<"x^2"<<p.b<<"x+"<<p.c<<";";
        return output;
    };
    ratio delta(){
        return b*b-mul(a*c,4);
    };
    /* real root1(){
        return (-b+sqrt(delta()))/(2*a);
    };
    real root2(){
        return (-b-sqrt(delta()))/(2*a);
    }; */
    point_r top(){
        return point_r(b/mul(a,-2),(mul(a*c,4)-b*b)/mul(a,4));
    };
};