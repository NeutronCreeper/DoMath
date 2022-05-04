#define RATIO

#include<iostream>
#ifndef MATHPLUS
#include "../.common/mathplus.h"
#endif
#ifndef SAMKHYA
#include "../samkhya/samkhya.h"
#endif

class ratio{
    private:
    long p=0;
    unsigned short q=1;
    public:
    void simplify(){
        long x=gcdl(p,q);
        p/=x;
        q/=x;
        if(q<0){
            q=bitneg(q);
            p=bitneg(p);
        };
    };
    inline ratio(long a=0,unsigned short b=1){
        p=a;
        q=b;
    };
    inline ratio(const ratio& m){
        p=m.p;
        q=m.q;
    };
    void operator()(long a=0,unsigned short b=1){
        p=a;
        q=b;
    };
    void operator()(const ratio& m){
        p=m.p;
        q=m.q;
    };
    long getp(){
        return p;
    };
    unsigned short getq(){
        return q;
    };
    bool operator==(const ratio& m){
        return (p==m.p)&&(q==m.q);
    };
    bool operator==(const short m){
        simplify();
        return (p==m)&&(q==1);
    };
    void operator=(const ratio& m){
        p=m.p;
        q=m.q;
    };
    void operator=(const short m){
        p=m;
        q=1;
    };
    void operator+=(const ratio& m){
        p*=m.q;
        p+=m.p*q;
        q*=m.q;
    };
    void operator+=(const short m){
        p+=m*q;
        simplify();
    };
    void operator-=(const ratio& m){
        p*=m.q;
        p-=m.p*q;
        q*=m.q;
    };
    void operator-=(const short m){
        p-=m*q;
        simplify();
    };
    void operator*=(const ratio& m){
        p*=m.p;
        q*=m.q;
    };
    void operator*=(const short m){
        p*=m;
        simplify();
    };
    void operator/=(const ratio& m){
        p*=m.q;
        q*=m.p;
    };
    void operator/=(const short m){
        q*=m;
        simplify();
    };
    ratio operator-(){
        return ratio(bitneg(p),q);
    };
    ratio operator+(const ratio& m){
        ratio ans(p*m.q+q*m.p,q*m.q);
        ans.simplify();
        return ans;
    };
    ratio operator+(const short m){
        return ratio(p+m*q,q);
    };
    ratio operator-(const ratio& m){
        ratio ans(p*m.q-q*m.p,q*m.q);
        ans.simplify();
        return ans;
    };
    ratio operator-(const short m){
        return ratio(p-m*q,q);
    };
    ratio operator*(const ratio& m){
        ratio ans(p*m.p,q*m.q);
        ans.simplify();
        return ans;
    };
    ratio operator*(const short m){
        return ratio(p*m,q);
    };
    ratio operator/(const ratio& m){
        ratio ans(p*m.q,q*m.p);
        ans.simplify();
        return ans;
    };
    ratio operator/(const short m){
        return ratio(p,q*m);
    };
    bool operator>(const ratio& m){
        return p/q>m.p/m.q;
    };
    bool operator>(const short m){
        return p/q>m;
    };
    bool operator<(const ratio& m){
        return p/q<m.p/m.q;
    };
    bool operator<(const short m){
        return p/q<m;
    };
    void operator++(){
        p+=q;
    };
    void operator--(){
        p-=q;
    };
    friend std::ostream& operator<<(std::ostream& output,const ratio& m){
        output<<'('<<m.p<<'/'<<m.q<<')';
        return output;
    };
    friend std::istream& operator>>(std::istream& input,ratio& m){
        input>>m.p>>m.q;
        if(input){
            m.simplify();
        }else{
            m.p=0;
            m.q=1;
            throw "Bad input!;\n";
        };
        return input;
    };
    explicit operator short(){
        return (short)p/q;
    };
    explicit operator int (){
        return (int)(p/q);
    };
    explicit operator float (){
        return (float)(p/(float)q);
    };
    explicit operator double (){
        return (double)(p/(double)q);
    };
    void read(const char* notice="\nratio=p/q,(p,q)=\n"){
        printf(notice);
        std::cin>>p>>q;
    };
    void from_float(const float& a){
        p=a*60000;
        q=60000;
        simplify();
    };
    friend inline void prints(const ratio& a);
};