#define RECTCOORD

#ifndef iostream
#include<iostream>
#endif
#ifndef MATHPLUS
#include "mathplus.h"
#endif

template<typename coord=float>class point{
    private:
    coord x,y;
    public:
    point(coord a=0,coord b=0){
        x=a;
        y=b;
    };
    void operator()(coord a=0,coord b=0){
        x=a;
        y=b;
    };
    void operator=(const point<coord>& P){
        x=P.x;
        y=P.y;
    };
    bool operator==(const point<coord>& P){
        if((x==P.x)&&(y==P.y)) return true;
        return false;
    };
    void operator+=(const point<coord>& P){
        x+=P.x;
        y+=P.y;
    };
    void operator-=(const point<coord>& P){
        x-=P.x;
        y-=P.y;
    };
    point operator+(const point<coord>& P){
        return point(x+P.x,y+P.y);
    };
    point operator-(const point<coord>& P){
        return point(x-P.x,y-P.y);
    };
    friend std::ostream& operator<<(std::ostream& output,const point<coord>& m){
        output<<'('<<m.x<<','<<m.y<<')';
        return output;
    };
    coord getx(){
        return x;
    };
    coord gety(){
        return y;
    };
};




template<typename coefficient=float>class line{
    private:
    coefficient k,b;
    char name='l';
    public:
    line(coefficient x=1,coefficient y=0){
        k=x;
        b=y;
    };
    void operator=(const line<coefficient>& l){
        k=l.k;
        b=l.b;
    };
    bool operator==(const line<coefficient>& l){
        if((k==l.k)&&(b==l.b)) return true;
        return false;
    };
    friend std::ostream& operator<<(std::ostream& output,const line<coefficient>& m){
        output<<'{'<<m.name<<":y="<<m.k<<"x+"<<m.b<<'}';
        return output;
    };
    void operator()(coefficient x=1,coefficient y=0,char c='l'){
        k=x;
        b=y;
        name=c;
    };
    coefficient getk(){
        return k;
    };
    coefficient getb(){
        return b;
    };
    coefficient valueofY(coefficient x){
        return k*x+b;
    };
    coefficient valueofX(coefficient y){
        return (y-b)/k;
    };
    bool parallel(const line<coefficient>& l){
        if(k==l.k) return true;
        return false;
    };
    bool vertical(const line<coefficient>& l){
        if(k*l.k==-1) return true;
        return false;
    };
    //friend template solve_from_line(const line<num>& i,const line<num>& j);
};



template<typename num=float>point<num> solve_from_line(line<num>& i,line<num>& j){
    point<num> ans;
    if(i.getk()==j.getk()){
        cout<<"[Warning]PARALLEL: No intersection;\n";
        ans(0,0);
        return ans;
    }
    num x=((j.getb()-(num)i.getb())/(i.getk()-j.getk()));
    ans(x,i.getk()*x+i.getb());
    return ans;
};

template<typename num=float>line<num> solve_from_point(point<num>& m,point<num>& n){
    if(m.getx()==n.getx()) std::cout<<"[Warning]An unsolved problem occured;\n";
    num k=((m.gety())-(n.gety()))/((m.getx())-(n.getx()));
    return line<num>(k,(m.gety())-(k*(m.getx())));
};

template<typename num>num areaofTriangle(point<num>& A,point<num>& B,point<num>& C){ 
    line<num> l=solve_from_point<num>(B,C);
    return std::abs(A.gety()-l.valueofY(A.getx()))*std::abs(B.getx()-C.getx())/2;
};