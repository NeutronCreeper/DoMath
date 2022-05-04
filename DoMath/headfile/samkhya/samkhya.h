#define SAMKHYA

#include<iostream>
#include<cmath>
#ifndef MATHPLUS
#include "../.common/mathplus.h"
#endif
#ifndef PRIME
#include "../prime/prime.h"
#endif

bool ifpow(const long& m,const unsigned char n=2){
    if((m<0)&&(n%2==0)) return false;
    float a=pow(m,(float)((float)1/(float)n));
    return (float)a==(int)a;
};

short gcd(short m,short n){
    m=bitabs(m);
    n=bitabs(n);
    if(!n) return m;
    if(m<n) return gcd(n%m,m);
    return gcd(m%n,n);
};

long gcdl(long m,long n){
    m=bitabs(m);
    n=bitabs(n);
    if(m<n) std::swap(m,n);
    if(!n) return m;
    return gcdl(m%n,n);
};

inline short lcm(short m,short n){
    return m*n/gcd(m,n);
};

inline long lcml(long& m,long& n){
    return m*n/gcdl(m,n);
};