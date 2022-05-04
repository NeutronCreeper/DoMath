#define _CMDS

#include<iostream>
#ifndef _CMDS_PRIME
#include "prime/_cmds.h"
#endif
#ifndef _CMDS_SAMKHYA
#include "samkhya/_cmds.h"
#endif
#ifndef _CMDS_RATIO
#include "ratio/_cmds.h"
#endif
#ifndef _CMDS_RECTCOORD
#include "rectcoord/_cmds.h"
#endif
#ifndef _CMDS_PARABOLA
#include "parabola/_cmds.h"
#endif
#ifndef _CMDS_CIRCLE
#include "circle/_cmds.h"
#endif
#ifndef LAZYARR
#include ".common/lazyarr.h"
#endif

void test(int flag){
    std::cout<<"Command test is successful;\n";
};
void cls(int flag){
    system("@cls||clear");
};
void pause(int flag){
    system("pause");
};
void sys(int flag){
    std::cout<<"system: ";
    std::string a;
    std::cin>>a;
    system(a.c_str());
};


struct cmd{
    std::string command_name;
    void (*command_)(int);
    inline cmd(const char* name,void (*_)(int)){
        command_=_;
        command_name=name;
    };
};
const cmd commands[]={
    //1-5
    cmd("exit",exit),
    cmd("test",test),
    cmd("cls",cls),
    cmd("pause",pause),
    cmd("sys",sys),
    //6-10
    cmd("ifsqr",samkhya_cmds::issqr),
    cmd("factorize",prime_cmds::factorize),
    cmd("gcd",samkhya_cmds::GCD),
    cmd("lcm",samkhya_cmds::LCM),
    cmd("primels",prime_cmds::primelist),
    //11-15
    cmd("ifpow",samkhya_cmds::ispow),
    cmd("solveparabola",parabola_cmds::solveparabola),
    cmd("toppoint",parabola_cmds::toppoint),
    cmd("prime",prime_cmds::isprime),
    cmd("solveline",rectcoord_cmds::solveline),
    //16-20
    cmd("solvepoint",rectcoord_cmds::solvepoint),
    cmd("r+",ratio_cmds::ratio_add),
    cmd("r-",ratio_cmds::ratio_sub),
    cmd("r*",ratio_cmds::ratio_mul),
    cmd("r/",ratio_cmds::ratio_div),
};
const int cmdnum=20;