#define _CMDS_PRIME
//built-in commands for "prime.h"
#ifndef PRIME
#include "prime.h"
#endif

namespace prime_cmds{

void isprime(int flag){
    std::cout<<"Please type in a positive integer to check if it is prime;\n";
    unsigned long a;
    std::cin>>a;
    bool isprime;
    if(!std::cin.good()) throw "Not a positive integer!\n";
    if(a<65536) isprime=prime((short)a);
    else isprime=primel(a);
    if(isprime) std::cout<<a<<" is a prime number;\n";
    else std::cout<<a<<" is not a prime number;\n";
};

void factorize(int flag){
    std::cout<<"Please type in an integer to factorize;\n";
    long a;
    std::cin>>a;
    if(!std::cin.good()) throw "Not a legal integer!\n";
    if(!primel(a)){
        long* factors=getPrimeFactors(a);
        std::cout<<"Altogether: "<<factors[0]<<" prime factors;\n"<<a<<'=';
        for(char i=1;i<factors[0];i++) std::cout<<factors[i]<<'*';
        std::cout<<factors[factors[0]]<<";\n";
        delete[] factors;
    }else std::cout<<a<<" is a prime number;\n";
};

void primelist(int flag){
    std::cout<<"Please type in a positive integer to list prime numbers under it;\n";
    unsigned short a;
    std::cin>>a;
    if(!std::cin.good()) throw "Not a positive integer!\n";
    char lenlimit=0;
    short count=0;
    for(short i=0;primes16[i]<a;i++){
        std::cout<<primes16[i]<<' ';
        count++;
        lenlimit++;
        if(lenlimit>15){
            std::cout<<'\n';
            lenlimit=0;
        };
    };
    std::cout<<"\nAltogether: "<<count<<";\n";
};

}