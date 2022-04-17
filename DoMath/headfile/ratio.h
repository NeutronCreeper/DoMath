#define RATIO

#include<iostream>
#ifndef SAMKHYA
#include"samkhya.h"
#endif

class ratio{
    //ratio:p/q
    private:
    long p=0;
    unsigned short q=1;
    public:
    void simplify(){
        long x=gcd(p,q);
        p/=x;
        q/=x;
        if(q<0){
            q=~q+1;
            p=~p+1;
        };
    };
    inline ratio(long a=0,unsigned short b=1){
        if(b<0){
            q=~b+1;
            p=~a+1;
        }
        p=a;
        q=b;
    };
    void set(long m,short n=1){
        p=m;
        q=n;
    };
    void operator()(long a,unsigned short b){
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
        if(this->p*m.q==this->q*m.p) return true;
        return false;
    };
    void operator=(const ratio& m){
        p=m.p;
        q=m.q;
    };
    void operator+=(const ratio& m){
        p*=m.q;
        p+=m.p*q;
        q*=m.q;
    };
    void operator-=(const ratio& m){
        p*=m.q;
        p-=m.p*q;
        q*=m.q;
    };
    void operator*=(const ratio& m){
        p*=m.p;
        q*=m.q;
    };
    void operator/=(const ratio& m){
        p*=m.q;
        q*=m.p;
    };
    ratio operator+(const ratio& m){
        ratio ans;
        ans.p=p*m.q+q*m.p;
        ans.q=q*m.q;
        return ans;
    };
    ratio operator-(const ratio& m){
        ratio ans;
        ans.p=this->p*m.q-this->q*m.p;
        ans.q=this->q*m.q;
        return ans;
    };
    ratio operator*(const ratio& m){
        ratio ans;
        ans.p=this->p*m.p;
        ans.q=this->q*m.q;
        return ans;
    };
    ratio operator/(const ratio& m){
        ratio ans;
        ans.p=this->p*m.q;
        ans.q=this->q*m.p;
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
        }
        return input;
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
    int to_integer(){
        return p/q;
    };
    float to_float(){
        return p/q;
    };
    ratio abs(){
        simplify();
        if(p<0){
            ratio ans;
            ans.p=~p+1;
            ans.q=q;
            return ans;
        }
        return *this;
    };
    ratio pow(const unsigned char& n){
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
};
ratio add(const ratio& m,const short& n){
    ratio ans=m;
    ans.add(n);
    return ans;
};
ratio sub(const ratio& m,const short& n){
    ratio ans=m;
    ans.sub(n);
    return ans;
};
ratio mul(const ratio& m,const short& n){
    ratio ans=m;
    ans.mul(n);
    return ans;
};
ratio div(const ratio& m,const short& n){
    ratio ans=m;
    ans.div(n);
    return ans;
};
ratio to_ratiof(float n){
    ratio ans((long)60000*n,60000);
    ans.simplify();
    return ans;
};