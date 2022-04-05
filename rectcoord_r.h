#define RECTCOORD_R

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
    void operator=(const point_r& P){
        x=P.x;
        y=P.y;
    };
    bool operator==(const point_r& P){
        if((x==P.x)&&(y==P.y)) return true;
        return false;
    };
    void print(){
        x.simplify();
        y.simplify();
        cout<<name<<'(';
        x.print();
        cout<<',';
        y.print();
        cout<<");\n";
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
    friend point_r point_r_create(const ratio& a,const ratio& b);
};
point_r point_r_create(const ratio& a,const ratio& b){
    point_r ans;
    ans.x=a;
    ans.y=b;
    return ans;
};

class line_r{
    private:
    ratio k,b;
    char name='l';
    public:
    void operator=(const line_r& l){
        k=l.k;
        b=l.b;
    };
    bool operator==(const line_r& l){
        if((k==l.k)&&(b==l.b)) return true;
        return false;
    };
    void print(){
        k.simplify();
        b.simplify();
        cout<<name<<":y=";
        k.print();
        cout<<"x+";
        b.print();
        cout<<";\n";
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
        if(k*l.k==to_ratio(-1)) return true;
        return false;
    };
};


/* liner solveliner(pointr* m,pointr* n){
    liner ans;
    if((m->getx())==(n->getx())) cout<<"[Warning]VERTICAL: Zero divided;\n";
    ratio k;
    k=((m->gety())-(n->gety()))/((m->getx())-(n->getx()));
    ans.set(k,((m->gety())-(k*(m->getx()))));
    return ans;
}; */
/* pointr solvepointr(liner* i,liner* j){
    pointr ans;
    if(i->getk()==j->getk()){
        cout<<"[Warning]PARALLEL: No intersection;\n";
        ans.set(to_ratio(0),to_ratio(0));
        return ans;
    }
    ratio x=((j->getb()-i->getb())/(i->getk()-j->getk()));
    ans.set(x,i->getk()*x+i->getb());
    return ans;
}; */
/* ratio areaofTriangler(pointr* A,pointr* B,pointr* C){
    ratio ans;
    ans=(absr(A->gety()-solveliner(B,C).valueofY(A->getx()))*absr(B->getx()-C->getx()));
    ans.mulc(2);
    return ans;
}; */