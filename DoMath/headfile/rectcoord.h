#define RECTCOORD

#ifndef iostream
#include<iostream>
#endif

using namespace std;

class point{
    private:
    float x,y;
    char name='P';
    public:
    point(float a=0,float b=0){
        x=a;
        y=b;
    };
    void operator=(const point& P){
        x=P.x;
        y=P.y;
    };
    bool operator==(const point& P){
        if((x==P.x)&&(y==P.y)) return true;
        return false;
    };
    void operator+=(const point& P){
        x+=P.x;
        y+=P.y;
    };
    void operator-=(const point& P){
        x-=P.x;
        y-=P.y;
    };
    point operator+(const point& P){
        point ans;
        ans.x=x+P.x;
        ans.y=y+P.y;
        return ans;
    };
    point operator-(const point& P){
        point ans;
        ans.x=x-P.x;
        ans.y=y-P.x;
        return ans;
    };
    friend std::ostream& operator<<(std::ostream& output,const point& m){
        output<<m.name<<'('<<m.x<<'/'<<m.y<<')';
        return output;
    };
    void set(float a,float b,char c='P'){
        x=a;
        y=b;
        name=c;
    };
    float getx(){
        return x;
    };
    float gety(){
        return y;
    };
    friend float areaofTrianglef(point& A,point& B,point& C);
};

class line{
    private:
    float k,b;
    char name='l';
    public:
    line(float x=1,float y=0){
        k=x;
        b=y;
    };
    void operator=(const line& l){
        k=l.k;
        b=l.b;
    };
    bool operator==(const line& l){
        if((k==l.k)&&(b==l.b)) return true;
        return false;
    };
    friend std::ostream& operator<<(std::ostream& output,const line& m){
        output<<'{'<<m.name<<":y="<<m.k<<"x+"<<m.b<<'}';
        return output;
    };
    void set(float x,float y,char c='l'){
        k=x;
        b=y;
        name=c;
    };
    float getk(){
        return k;
    };
    float getb(){
        return b;
    };
    float valueofY(float x){
        return k*x+b;
    };
    float valueofX(float y){
        return (y-b)/k;
    };
    bool parallel(line l){
        if(k==l.k) return true;
        return false;
    };
    bool vertical(line l){
        if(k*l.k==-1) return true;
        return false;
    };
    void solve_from_point(point& m,point& n){
        if(m.getx()==n.getx()) std::cout<<"[Warning]An unsolved problem occured;\n";
        k=((m.gety())-(n.gety()))/((m.getx())-(n.getx()));
        b=((m.gety())-(k*(m.getx())));
    };
    friend point solve_from_line(line& i,line& j);
};

point solve_from_line(line& i,line& j){
    point ans;
    if(i.k==j.k){
        cout<<"[Warning]PARALLEL: No intersection;\n";
        ans.set(0,0);
        return ans;
    }
    float x=((j.b-i.b)/(i.k-j.k));
    ans.set(x,i.k*x+i.b);
    return ans;
};
float areaofTrianglef(point& A,point& B,point& C){
    line l;
    l.solve_from_point(B,C);
    return std::abs(A.y-l.valueofY(A.x))*std::abs(B.x-C.x)/2;
};