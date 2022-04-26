#define PRIME

#include<iostream>
#include<cmath>
#ifndef MATHPLUS
#include "../.common/mathplus.h"
#endif
#ifndef PRIMES8
#include "primes8.h"
#endif
#ifndef PRIMES16
#include "primes16.h"
#endif

bool prime(const unsigned short& p){
    unsigned char i=0;
    if(p<2) return false;
    do{
        if((p%primes8[i]==0)&&(p!=primes8[i]))  return false;
        i++;
    }while((i<54)&&(primes8[i]<p));
    return true;
};

#ifdef PRIMES16
bool primel(const unsigned long& p){
    unsigned short i=0;
    if(p<2) return false;
    if(p==2) return true;
    do{
        if((p%primes16[i]==0)&&(p!=primes16[i])) return false;
        i++;
    }while((i<6542)&&(primes16[i]<p));
    return true;
};
#endif

#ifndef PRIMES16
bool primel(const unsigned long& p){
    if(p<2) return false;
    if(p==2) return true;
    unsigned short i=2;
    unsigned short m=std::sqrt(p)+1;
    do{
        if(prime(i)){
            if(p%i==0) return false;
        };
        i++;
    }while(i<m);
    return true;
};
#endif

long* getPrimeFactors(unsigned long n){
    n=mthpabs(n);
    long* anss= new long[33];
    short count=0;
    unsigned short i=2;
    do{
        if(prime(i)&&(n%i==0)){
            count++;
            anss[count]=i;
            n/=i;
        }else{
            i++;
        };
    }while(!primel(n));
    count++;
    anss[count]=n;
    anss[0]=count;
    count++;
    while(count<33){
        delete (anss+count);
        count++;
    };
    return anss;
};