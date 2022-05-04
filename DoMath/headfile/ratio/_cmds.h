#define _CMDS_RATIO

#include<iostream>
#ifndef RATIO
#include "ratio.h"
#endif

namespace ratio_cmds{

void ratio_add(int flag){
    std::cout<<"Please type in 2 ratios to add;\nratio=p/q, (p1/q1)+(p2/q2), type in (p1,p2,q1,q2);\n";
    long p,r;
    short q,s;
    std::cin>>p>>q>>r>>s;
    if(!std::cin.good()) throw "Not legal integers!\n";
    ratio a(p,q),b(r,s);
    std::cout<<a<<'+'<<b<<'='<<a+b<<";\n";
};

void ratio_sub(int flag){
    std::cout<<"Please type in 2 ratios to substract;\nratio=p/q, (p1/q1)-(p2/q2), type in (p1,p2,q1,q2);\n";
    long p,r;
    short q,s;
    std::cin>>p>>q>>r>>s;
    if(!std::cin.good()) throw "Not legal integers!\n";
    ratio a(p,q),b(r,s);
    std::cout<<a<<'-'<<b<<'='<<a-b<<";\n";
};

void ratio_mul(int flag){
    std::cout<<"Please type in 2 ratios to multiply;\nratio=p/q, (p1/q1)*(p2/q2), type in (p1,p2,q1,q2);\n";
    long p,r;
    short q,s;
    std::cin>>p>>q>>r>>s;
    if(!std::cin.good()) throw "Not legal integers!\n";
    ratio a(p,q),b(r,s);
    std::cout<<a<<'*'<<b<<'='<<a*b<<";\n";
};

void ratio_div(int flag){
    std::cout<<"Please type in 2 ratios to divide;\nratio=p/q, (p1/q1)/(p2/q2), type in (p1,p2,q1,q2);\n";
    long p,r;
    short q,s;
    std::cin>>p>>q>>r>>s;
    if(!std::cin.good()) throw "Not legal integers!\n";
    ratio a(p,q),b(r,s);
    std::cout<<a<<'/'<<b<<'='<<a/b<<";\n";
};

}