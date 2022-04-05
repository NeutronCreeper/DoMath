#define RECTCOORD

#ifndef iostream
#include<iostream>
#endif

using namespace std;

class point{
    private:
    float x=0,y=0;
    char name='P';
    public:
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
    void print(){
        std::cout<<name<<'('<<x<<','<<y<<");\n";
    };
    std::string expression(){
        return name+"("+to_string(x)+","+to_string(y)+");\n";
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
    //friend point point_create(const float& a,const float& b,char c='P');
    friend float areaofTrianglef(point& A,point& B,point& C);
};
/* point point_create(const float& a,const float& b,char c='P'){
    point ans;
    ans.x=a;
    ans.y=b;
    ans.name=c;
    return ans;
}; */
class line{
    private:
    float k=0,b=0;
    char name='l';
    public:
    void operator=(const line& l){
        k=l.k;
        b=l.b;
    };
    bool operator==(const line& l){
        if((k==l.k)&&(b==l.b)) return true;
        return false;
    };
    void print(){
        std::cout<<name<<":y="<<k<<"x+"<<b<<";\n";
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
    //friend line line_create(const float& x,const float& y,char c='l');
    friend point solve_from_line(line& i,line& j);
};
/* line line_create(const float& x,const float& y,char c='l'){
    line ans;
    ans.k=x;
    ans.b=y;
    ans.name=c;
    return ans;
}; */
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
