#define RECTCOORD_RATIO

#ifndef iostream
#include<iostream>
#endif
#ifndef RATIO
#include "ratio.h"
#endif

using namespace std;

class point_r{
    private:
    ratio x,y;
    char name='P';
    public:
    point_r(ratio a=ratio(),ratio b=ratio()){
        x=a;
        y=b;
    };
    friend ostream& operator<<(ostream& output,const point_r& P){
        output<<P.name<<'('<<P.x<<','<<P.y<<')';
        return output;
    };
    void operator=(const point_r& P){
        x=P.x;
        y=P.y;
    };
    bool operator==(const point_r& P){
        if((x==P.x)&&(y==P.y)) return true;
        return false;
    };
    void set(ratio a,ratio b,char c='P'){
        x=a;
        y=b;
        name=c;
    };
    ratio getx(){
        return x;
    };
    ratio gety(){
        return y;
    };
    friend ratio areaofTriangle_r(point_r& A,point_r& B,point_r& C);
};

class line_r{
    private:
    ratio k,b;
    char name='l';
    public:
    line_r(ratio x=ratio(1,1),ratio y=ratio()){
        k=x;
        b=y;
    };
    void operator=(const line_r& l){
        k=l.k;
        b=l.b;
    };
    bool operator==(const line_r& l){
        if((k==l.k)&&(b==l.b)) return true;
        return false;
    };
    friend ostream& operator<<(ostream& output,const line_r& i){
        output<<'{'<<i.name<<":y="<<i.k<<"x+"<<i.b<<'}';
        return output;
    };
    void set(ratio& x,ratio& y,char c='l'){
        k=x;
        b=y;
        name=c;
    };
    void simplify(){
        k.simplify();
        b.simplify();
    };
    ratio getk(){
        return k;
    };
    ratio getb(){
        return b;
    };
    ratio valueofY(ratio& x){
        return x*k+b;
    };
    ratio valueofX(ratio& y){
        return (y-b)/k;
    };
    bool parallel(line_r& l){
        if(k==l.k) return true;
        return false;
    };
    bool vertical(line_r& l){
        if(k*l.k==ratio(-1)) return true;
        return false;
    };
    void solve_from_point_r(point_r& m,point_r& n){
        line_r ans;
        if(m.getx()==n.getx()) cout<<"[Warning]VERTICAL: Zero divided;\n";
        k=((m.gety())-(n.gety()))/((m.getx())-(n.getx()));
        b=(m.gety())-(k*(m.getx()));
    };
    friend ratio areaofTriangle_r(point_r& A,point_r& B,point_r& C);
};

point_r solve_from_line_r(line_r& i,line_r& j){
    point_r ans;
    if(i.getk()==j.getk()){
        cout<<"[Warning]PARALLEL: No intersection;\n";
        ans.set(ratio(0),ratio(0));
        return ans;
    }
    ratio x=((j.getb()-i.getb())/(i.getk()-j.getk()));
    ans.set(x,i.getk()*x+i.getb());
    return ans;
}
ratio areaofTriangle_r(point_r& A,point_r& B,point_r& C){
    ratio ans;
    line_r l;
    l.solve_from_point_r(B,C);
    ans=(A.y-l.valueofY(A.x)).abs()*(B.x-C.x).abs();
    ans.div(2);
    return ans;
};