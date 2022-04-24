#define SHELL

#ifndef iostream
#include<iostream>
#endif
#include<string.h>
#include "headfile\cmds.h"

void test(int flag){
    std::cout<<"Command test is successful;\n";
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

int shell(std::string arg="\n"){
    std::cout<<arg+'\n';
    std::cout<<"<DoMath>shell: Hi!\n";
    newcommand:;
    std::cout<<"DoMath-shell>> ";
    std::string command;
    std::cin>>command;
    for(int temp=0;temp<cmdnum;temp++){
        if(command.compare(commands[temp].command_name)==0){
            try{
                commands[temp].command_(0);
                goto newcommand;
            }catch(const char* msg){
                std::cerr<<msg;
                std::cout<<"Command failed to execute.\n";
                std::cin.clear();
                std::cin.ignore();
                goto newcommand;
            };
        };
    };
    std::cout<<"Unknown command!\n";
    std::cin.clear();
    std::cin.ignore();
    goto newcommand;
    return 0;
};