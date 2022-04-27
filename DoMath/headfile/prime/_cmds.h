#define _CMDS_PRIME
//built-in commands for "prime.h"
#ifndef PRIME
#include "prime.h"
#endif

namespace prime_cmds{

void isprime(int flag){
    printf("Please type in a positive integer to check if it is prime;\n");
    unsigned long a;
    std::cin>>a;
    bool isprime;
    if(!std::cin.good()){
        throw "Not a positive integer!\n";
    }else if(a<65536){
        isprime=prime((short)a);
    }else{
        isprime=primel(a);
    };
    if(isprime){
        printf("%ld is a prime number;\n",a);
    }else{
        printf("%ld is not a prime number;\n",a);
    };
};

void factorize(int flag){
    printf("Please type in an integer to factorize;\n");
    long a;
    std::cin>>a;
    if(!std::cin.good()){
        throw "Not a legal integer!\n";
    }else if(!primel(a)){
        long* factors=getPrimeFactors(a);
        printf("Altogether: %ld prime factors;\n%ld=",factors[0],a);
        for(char i=1;i<factors[0];i++) printf("%ld*",factors[i]);
        printf("%ld;\n",factors[factors[0]]);
    }else{
        printf("%ld is a prime number;\n",a);
    };
};

void primelist(int flag){
    printf("Please type in a positive integer to list prime numbers under it;\n");
    unsigned short a;
    std::cin>>a;
    if(!std::cin.good()){
        throw "Not a positive integer!\n";
    };
    char lenlimit=0;
    short count=0;
    for(short i=0;primes16[i]<a;i++){
        printf("%d ",primes16[i]);
        count++;
        lenlimit++;
        if(lenlimit>15){
            printf("\n");
            lenlimit=0;
        };
    };
    printf("\nAltogether: %d;\n",count);
};

}