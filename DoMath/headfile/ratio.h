#define RATIO

#include<iostream>
#ifndef SAMKHYA
#include"samkhya.h"
#endif

class ratio{
    //ratio:p/q
    friend ratio ratio_create(long a,short b);
    private:
    long p=0;
    short q=1;
    public:
    void set(long m,short n=1){
        p=m;
        q=n;
    };
    long getp(){
        return p;
    };
    long getq(){
        return q;
    };
    void simplify(){
        long x=gcd(p,q);
        p/=x;
        q/=x;
        if(q<0){
            q=~q+1;
            p=~p+1;
        };
    };
    ratio(long a=0,short b=1){
        p=a;
        q=b;
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
    friend std::ostream& operator<<(std::ostream& output,const ratio& m){
        output<<'('<<m.p<<'/'<<m.q<<')';
        return output;
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
    ratio pow(const short& n){
        ratio ans;
        ans.simplify();
        ans.p=pow_integer(p,n);
        ans.q=pow_integer(q,n);
        return ans;
    };
    friend ratio add(const ratio& m,const short& n);
    friend ratio sub(const ratio& m,const short& n);
    friend ratio mul(const ratio& m,const short& n);
    friend ratio div(const ratio& m,const short& n);
};
ratio ratio_create(long a,short b=1){
    ratio ans;
    ans.p=a;
    ans.q=b;
    return ans;
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
ratio to_ratio(short n){
    return ratio_create(n,1);
};
ratio to_ratiof(float n){
    ratio ans;
    ans.set((long)10000*n,10000);
    ans.simplify();
    return ans;
};