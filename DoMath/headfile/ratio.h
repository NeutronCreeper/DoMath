#define RATIO

#include<iostream>
#ifndef SAMKHYA
#include"samkhya.h"
#endif
#ifndef STRUCTURE
#include "structure.h"
#endif

class ratio{
    //ratio=p/q
    private:
    long p=0;
    unsigned short q=1;
    public:
    void simplify(){
        long x=gcdl(p,q);
        p/=x;
        q/=x;
        if(q<0){
            q=~q+1;
            p=~p+1;
        };
    };
    inline ratio(long a=0,unsigned short b=1){
        p=a;
        q=b;
    };
    void operator()(long a=0,unsigned short b=1){
        p=a;
        q=b;
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
    bool operator==(const short& m){
        simplify();
        return (p==m)&&(q==1);
    };
    void operator=(const ratio& m){
        p=m.p;
        q=m.q;
    };
    void operator=(const short& m){
        p=m;
        q=1;
    };
    void operator+=(const ratio& m){
        p*=m.q;
        p+=m.p*q;
        q*=m.q;
    };
    void operator+=(const short& m){
        p+=m*q;
        simplify();
    };
    void operator-=(const ratio& m){
        p*=m.q;
        p-=m.p*q;
        q*=m.q;
    };
    void operator-=(const short& m){
        p-=m*q;
        simplify();
    };
    void operator*=(const ratio& m){
        p*=m.p;
        q*=m.q;
    };
    void operator*=(const short& m){
        p*=m;
        simplify();
    };
    void operator/=(const ratio& m){
        p*=m.q;
        q*=m.p;
    };
    void operator/=(const short& m){
        q*=m;
        simplify();
    };
    ratio operator-(){
        return ratio(~p+1,q);
    };
    ratio operator+(const ratio& m){
        ratio ans(p*m.q+q*m.p,q*m.q);
        ans.simplify();
        return ans;
    };
    ratio operator+(const short& m){
        return ratio(p+m*q,q);
    };
    ratio operator-(const ratio& m){
        ratio ans(p*m.q-q*m.p,q*m.q);
        ans.simplify();
        return ans;
    };
    ratio operator-(const short& m){
        return ratio(p-m*q,q);
    };
    ratio operator*(const ratio& m){
        ratio ans(p*m.p,q*m.q);
        ans.simplify();
        return ans;
    };
    ratio operator/(const ratio& m){
        ratio ans(p*m.q,q*m.p);
        ans.simplify();
        return ans;
    };
    bool operator>(const ratio& m){
        return p/q>m.p/m.q;
    };
    bool operator<(const ratio& m){
        return p/q<m.p/m.q;
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
        }
        else{
            m.p=0;
            m.q=1;
            std::cout<<"Bad input!;\n";
        };
        return input;
    };
    explicit operator int (){
        return p/q;
    };
    explicit operator float (){
        return p/(float)q;
    };
    explicit operator double (){
        return p/(double)q;
    };
    void add(short m){
        p+=q*m;
    };
    void sub(short m){
        p-=q*m;
    };
    void mul(short m){
        p*=m;
        simplify();
    };
    void div(short m){
        q*=m;
    };
    ratio abs(){
        simplify();
        return ratio(mthpabs(p),q);
    };
    ratio pow(const unsigned char& n=2){
        ratio ans;
        ans.simplify();
        ans.p=pow_integer(p,n);
        ans.q=pow_integer(q,n);
        return ans;
    };
    void read(std::string notice="ratio=p/q,(p,q)="){
        std::cout<<'\n'<<notice<<":\n";
        std::cin>>p>>q;
    };
    void from_float(float& m){
        p=60000*m;
        q=60000;
    };
};

//