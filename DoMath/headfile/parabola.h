#define PARABOLA

#ifndef iostream
#include<iostream>
#endif
#ifndef cmath
#include<cmath>
#endif
#ifndef RECTCOORD
#include "rectcoord.h"
#endif


template<typename parameter>class parabola{
    private:
    parameter a,b,c;
    public:
    parabola(parameter x=1,parameter y=0,parameter z=0){
        a=x;
        b=y;
        c=z;
    };
    void operator=(parabola w){
        a=w.a;
        b=w.b;
        c=w.c;
    };
    bool operator==(parabola w){
        if((a==w.a)&&(b==w.b)&&(c==w.c)) return true;
        return false;
    };
    void operator()(parameter p=1,parameter q=0,parameter r=0,bool akm=false){
        if(akm){
            r+=(p*pow(q,2)-(4*p*r));
            q*=(2*p);
        }
        a=p;
        b=q;
        c=r;
    };
    friend std::ostream& operator<<(std::ostream& output,const parabola& m){
        output<<"{parabola:y="<<m.a<<"x^2+"<<m.b<<"x+"<<m.c<<'}';
        return output;
    };
    parameter geta(){
        return a;
    };
    parameter getb(){
        return b;
    };
    parameter getc(){
        return c;
    };
    parameter getm(){
        return b/(2*a);
    };
    parameter getk(){
        return c-(b*b)/(4*a);
    };
    parameter delta(){
        return pow(b,2)-4*a*c;
    };
    parameter root1(){
        return (-b+sqrt(delta()))/(2*a);
    };
    parameter root2(){
        return (-b-sqrt(delta()))/(2*a);
    };
    point<parameter> top(){
        point ans;
        ans.set(b/(-2*a),(4*a*c-pow(b,2))/(4*a));
        return ans;
    };
    friend void solve_from_point(point<parameter>& A,point<parameter>& B,point<parameter>& C){
        parameter x1=A.getx();
        parameter y1=A.gety();
        parameter x2=B.getx();
        parameter y2=B.gety();
        parameter x3=C.getx();
        parameter y3=C.gety();
        a=(x1*y2-x1*y3-x2*y1+x2*y3-x3*y2+x3*y1)/((x1-x3)*(x1-x2)*(x3-x2));
        b=((y1-y2)/(x1-x2))-((x1+x2)*a);
        c=y1-a*x1*x1-b*x1;
    };
};