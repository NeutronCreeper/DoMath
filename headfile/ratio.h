#define RATIO

#include<iostream>
#ifndef SAMKHYA
#include"samkhya.h"
#endif

class ratio{
    //ratio:p/q
    private:
    long p=0;
    short q=1;
    public:
    void set(long m,int n){
        p=m;
        q=n;
    };
    long getp(){
        return p;
    };
    long getq(){
        return q;
    };
    void copy(ratio* m){
        set(m->getp(),m->getq());
    };
    float value(){
        return p/q;
    };
    void print(){
        std::cout<<'('<<p<<'/'<<q<<')';
    };
    std::string expression(){
        return '('+std::to_string(p)+'/'+std::to_string(q)+')';
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
    friend ratio ratio_create(long a,short b);
    friend ratio add(const ratio& m,const short& n);
    friend ratio sub(const ratio& m,const short& n);
    friend ratio mul(const ratio& m,const short& n);
    friend ratio div(const ratio& m,const short& n);
};
ratio ratio_create(long a,short b){
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
ratio absr(ratio m){
    m.simplify();
    if(m.getq()>0) return m;
    m.mul(-1);
    return m;
};