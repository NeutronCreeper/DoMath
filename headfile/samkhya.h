#define SAMKHYA

#ifndef iostream
#include<iostream>
#endif
#ifndef cmath
#include<cmath>
#endif

bool prime(long* p){
    short m=sqrt(std::abs(*p))+1;
    for(int i=2;i<m;i++){
        if(*p%i==0) return false;
    }
    return true;
};
bool ifpow(long* m,short n=2){
    if(*m<0) return false;
    short i=(short)pow(*m,1/n);
    if(*m==pow(i,n)) return true;
    return false;
};
long gcd(long m,long n){
    m=std::abs(m);
    n=std::abs(n);
    if(m<n) std::swap(m,n);
    if(n==0) return m;
    return gcd(m-n,n);
};
long lcm(long* m,long* n){
    return *m*(*n)/gcd(*m,*n);
};
long pow_integer(const long& m,const short& n){
    return (long)std::round(std::pow(m,n));
};