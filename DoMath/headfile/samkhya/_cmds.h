#define _CMDS_SAMKHYA
//built-in commands for "samkhya.h"
#ifndef SAMKHYA
#include "samkhya.h"
#endif

namespace samkhya_cmds{

void issqr(int flag){
    printf("Please type in a positive integer to check if it is a square number;\n");
    unsigned long a;
    std::cin>>a;
    if(!std::cin.good()){
        throw "Not a positive integer!\n";
    }else{
        if(ifpow(a)){
            std::cout<<a<<"="<<std::sqrt(a)<<"^2;\n";
        }else{
            printf("%ldu");
            std::cout<<a<<" is not a square number;\n";
        };
    };
};

void GCD(int flag){
    printf("Please type in 2 integers to get the greatest common divisor;\n");
    long a,b;
    std::cin>>a>>b;
    if(std::cin.good()){
        printf("Greatest common divisor of (%ld,%ld) is %ld;\n",a,b,gcdl(a,b));
    }else{
        throw "Not legal integers!\n";
    };
};

void LCM(int flag){
    printf("Please type in 2 integers to get the least common multiple;\n");
    long a,b;
    std::cin>>a>>b;
    if(std::cin.good()){
        printf("Least common multiple of (%ld,%ld) is %ld;\n",a,b,lcml(a,b));
    }else{
        throw "Not legal integers!\n";
    };
};

void ispow(int flag){
    printf("Please type in 2 integers to check whether one is a certain number of power of an integer;\n");
    long a;
    short b;
    std::cin>>a>>b;
    if(std::cin.good()){
        if(ifpow(a,b)){
            printf("%ld=%ld^%d;\n",a,(int)pow(a,(float)1/(float)b),b);
        }else{
            printf("%ld is not the %d power of an integer;\n",a,b);
        };
    }else{
        throw "Not legal integers!\n";
    };
};

}