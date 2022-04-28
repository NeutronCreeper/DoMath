#define _CMDS

#include<iostream>
#include<string>
#ifndef _CMDS_PRIME
#include "prime/_cmds.h"
#endif
#ifndef _CMDS_SAMKHYA
#include "samkhya/_cmds.h"
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




void test(int flag){
    printf("Command test is successful;\n");
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
    cmd("solveline",rectcoord_cmds::solveline),
    cmd("solvepoint",rectcoord_cmds::solvepoint),
    cmd("prime",prime_cmds::isprime),
    //6-10
    cmd("ifsqr",samkhya_cmds::issqr),
    cmd("factorize",prime_cmds::factorize),
    cmd("gcd",samkhya_cmds::GCD),
    cmd("lcm",samkhya_cmds::LCM),
    cmd("primels",prime_cmds::primelist),
    //11-
    cmd("ifpow",samkhya_cmds::ispow),
    cmd("solveparabola",parabola_cmds::solveparabola),
    cmd("toppoint",parabola_cmds::toppoint),
};
const int cmdnum=13;