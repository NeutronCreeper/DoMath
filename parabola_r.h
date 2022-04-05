#define PARABOLA_R

#ifndef iostream
#include<iostream>
#endif
#ifndef RATIO
#include "ratio.h"
#endif
#ifndef RECTCOORD_R
#include "rectcoord_r.h"
#endif

class parabolar{
    private:
    ratio a,b,c;
    public:
    void set(ratio p,ratio q,ratio r,bool akm=0){
        if(akm){
            r+=(p*q*q-mul(p*r,4));
            q*=mul(p,2);;
        }
        a=p;
        b=q;
        c=r;
    };
    void print(){
        cout<<"parabola:y="<<a.expression()<<"x^2+"<<b.expression()<<"x+"<<c.expression()<<";\n";
    };
    ratio delta(){
        return b*b-mul(a*c,4);
    };
    /* float root1(){
        return (-b+sqrt(delta()))/(2*a);
    };
    float root2(){
        return (-b-sqrt(delta()))/(2*a);
    }; */
    point_r top(){
        point_r ans;
        ans.set(b/mul(a,-2),(mul(a*c,4)-b*b)/mul(a,4));
        return ans;
    };
};