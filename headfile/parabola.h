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

using namespace std;
class parabola{
    private:
    float a=1,b=0,c=0;
    public:
    void operator=(parabola w){
        a=w.a;
        b=w.b;
        c=w.c;
    };
    bool operator==(parabola w){
        if((a==w.a)&&(b==w.b)&&(c==w.c)) return true;
        return false;
    };
    void set(float p,float q,float r,bool akm=false){
        if(akm){
            r+=(p*pow(q,2)-(4*p*r));
            q*=(2*p);
        }
        a=p;
        b=q;
        c=r;
    };
    void print(){
        cout<<"parabola:y="<<a<<"x^2+"<<b<<"x+"<<c<<";\n";
    };
    float geta(){
        return a;
    };
    float getb(){
        return b;
    };
    float getc(){
        return c;
    };
    float getm(){
        return b/(2*a);
    };
    float getk(){
        return c-(b*b)/(4*a);
    };
    float delta(){
        return pow(b,2)-4*a*c;
    };
    float root1(){
        return (-b+sqrt(delta()))/(2*a);
    };
    float root2(){
        return (-b-sqrt(delta()))/(2*a);
    };
    point top(){
        point ans;
        ans.set(b/(-2*a),(4*a*c-pow(b,2))/(4*a));
        return ans;
    };
    void solve_from_point(point& A,point& B,point& C){
        float x1=A.getx();
        float y1=A.gety();
        float x2=B.getx();
        float y2=B.gety();
        float x3=C.getx();
        float y3=C.gety();
        a=(x1*y2-x1*y3-x2*y1+x2*y3-x3*y2+x3*y1)/((x1-x3)*(x1-x2)*(x3-x2));
        b=((y1-y2)/(x1-x2))-((x1+x2)*a);
        c=y1-a*x1*x1-b*x1;
    };
    //friend parabola parabola_create(float p,float q,float r,bool akm=false);
};
/* parabola parabola_create(float p,float q,float r,bool akm=false){
    parabola ans;
    ans.a=p;
    ans.b=q;
    ans.c=r;
    return ans;
}; */
parabola parabola_create(const float& p,const float& q,const float& r,bool akm=false){
    parabola ans;
    ans.set(p,q,r,akm);
    return ans;
};
/* parabola solveparabola(point* A,point* B,point* C){
    float x1=A->getx();
    float y1=A->gety();
    float x2=B->getx();
    float y2=B->gety();
    float x3=C->getx();
    float y3=C->gety();
    float a=(x1*y2-x1*y3-x2*y1+x2*y3-x3*y2+x3*y1)/((x1-x3)*(x1-x2)*(x3-x2));
    float b=((y1-y2)/(x1-x2))-((x1+x2)*a);
    float c=y1-a*x1*x1-b*x1;
    parabola w;
    w.set(a,b,c);
    return w;
}; */
