#define MONOMIAL

#include<iostream>
#ifndef ALGEBRA
#include "../algebra/algebra.h"
#endif
#ifndef CHAIN
#include "../.common/structure/chain.h"
#endif
#ifndef RATIO
#include "../ratio/ratio.h"
#endif

struct exponential{
    const algebra* a=nullptr;
    char exponent=1;
    inline exponential(const algebra* a_,char exponent_=1){
        a=a_;
        exponent=exponent_;
    };
    ~exponential(){
        a=nullptr;
    };
    void operator*=(const exponential& e){
        if(a!=e.a) throw "Exponential mutiplied with different base!\n";
        exponent+=e.exponent;
    };
    void operator/=(const exponential& e){
        if(a!=e.a) throw "Exponential divided with different base!\n";
        exponent-=e.exponent;
    };
    exponential operator*(const exponential& e){
        if(a!=e.a) throw "Exponential mutiplied with different base!\n";
        return exponential(a,exponent+e.exponent);
    };
    exponential operator/(const exponential& e){
        if(a!=e.a) throw "Exponential divided with different base!\n";
        return exponential(a,exponent-e.exponent);
    };
    void operator=(const exponential& e){
        a=e.a;
        exponent=e.exponent;
    };
    bool operator==(const exponential& e){
        return ((a==e.a)&&(exponent==e.exponent));
    };
    bool operator!=(const exponential& e){
        return ((a!=e.a)||(exponent!=e.exponent));
    };
    friend std::ostream& operator<<(std::ostream& output,const exponential& e){
        output<<"(("<<e.a->name<<")^"<<(int)e.exponent<<')';
        return output;
    };
};

struct monomial{
    ratio coefficient;
    chain<exponential> variables;
    inline monomial(){
        coefficient=0;
    };
    inline monomial(const ratio& r){
        coefficient=r;
    };
    inline monomial(const ratio& r,const exponential& e){
        coefficient=r;
        variables+=e;
    };
    inline monomial(const ratio& r,const chain<exponential>& ch){
        coefficient=r;
        variables+=ch;
    };
};