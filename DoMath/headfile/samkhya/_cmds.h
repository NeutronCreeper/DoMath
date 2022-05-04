#define _CMDS_SAMKHYA
//built-in commands for "samkhya.h"
#ifndef SAMKHYA
#include "samkhya.h"
#endif

namespace samkhya_cmds{

void issqr(int flag){
    std::cout<<"Please type in a positive integer to check if it is a square number;\n";
    unsigned long a;
    std::cin>>a;
    if(!std::cin.good()) throw "Not a positive integer!\n";
    else{
        if(ifpow(a)) std::cout<<a<<"="<<std::sqrt(a)<<"^2;\n";
        else std::cout<<a<<" is not a square number;\n";
    };
};

void GCD(int flag){
    std::cout<<"Please type in 2 integers to get the greatest common divisor;\n";
    long a,b;
    std::cin>>a>>b;
    if(std::cin.good()) std::cout<<"Greatest common divisor of ("<<a<<','<<b<<") is "<<gcdl(a,b)<<";\n";
    else throw "Not legal integers!\n";
};

void LCM(int flag){
    std::cout<<"Please type in 2 integers to get the least common multiple;\n";
    long a,b;
    std::cin>>a>>b;
    if(std::cin.good()) std::cout<<"Least common multiple of ("<<a<<','<<b<<") is "<<lcml(a,b)<<";\n";
    else throw "Not legal integers!\n";
};

void ispow(int flag){
    std::cout<<"Please type in 2 integers to check whether one is a certain number of power of an integer;\n";
    long a;
    short b;
    std::cin>>a>>b;
    if(std::cin.good()){
        if(ifpow(a,b)) std::cout<<a<<'='<<(int)pow(a,(float)((float)1/(float)b))<<'^'<<b<<";\n";
        else std::cout<<a<<" is not the "<<b<<" power of an integer;\n";
    }else throw "Not legal integers!\n";
};

}