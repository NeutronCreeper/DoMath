#define SAMKHYA

#ifndef iostream
#include<iostream>
#endif
#ifndef cmath
#include<cmath>
#endif
#ifndef MATHPLUS
#include "mathplus.h"
#endif
#ifndef PRIME
#include "prime.h"
#endif

bool ifpow(const long& m,const unsigned short& n=2){
    if((m<0)&&(n%2==0)) return false;
    float a=pow(m,(float)((float)1/(float)n));
    return (float)a==(int)a;
};

long gcdl(long m,long n){
    m=mthpabs(m);
    n=mthpabs(n);
    if(m<n) std::swap(m,n);
    if(!n) return m;
    return gcdl(m%n,n);
};

inline long lcm(long& m,long& n){
    return m*n/gcdl(m,n);
};

inline long pow_integer(const long& m,unsigned char n){
    return (long)std::round(std::pow(m,n));
};