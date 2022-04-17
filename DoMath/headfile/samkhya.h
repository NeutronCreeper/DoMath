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


inline bool prime(long p){
    short m=sqrt(mthpabs(p))+1;
    for(short i=2;i<m;i++){
        if(p%i==0) return false;
    }
    return true;
};
inline bool ifpow(long* m,short n=2){
    if(*m<0) return false;
    short i=(short)pow(*m,1/n);
    if(*m==pow(i,n)) return true;
    return false;
};
long gcd(long m,long n){
    m=mthpabs(m);
    n=mthpabs(n);
    if(m<n) std::swap(m,n);
    if(n==0) return m;
    return gcd(m%n,n);
};
inline long lcm(long& m,long& n){
    return m*n/gcd(m,n);
};
inline long pow_integer(const long& m,const short& n){
    return (long)std::round(std::pow(m,n));
};
long* getPrimeFactors(long n){
    n=mthpabs(n);
    long* anss= new long[33];
    short count=0;
    long i=2;
    do{
        if(prime(i)&&(n%i==0)){
            count++;
            anss[count]=i;
            n/=i;
            i=2;
        }
        i++;
    }while(!prime(n));
    count++;
    anss[count]=n;
    anss[0]=count;
    count++;
    while(count<33){
        delete (anss+count);
        count++;
    }
    return anss;
};