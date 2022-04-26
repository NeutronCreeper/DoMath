#define SHELL

#include<iostream>
#include<string.h>
#include "headfile/_cmds.h"
#include "info.h"




int shell(std::string arg=""){
    std::cout<<arg+'\n';
    std::cout<<"DoMath-shell<< start\n";
    newcommand:;
    std::cout<<"DoMath-shell>> ";
    std::string command;
    std::cin>>command;
    if(command=="info"){
        std::cout<<"DoMath version: "<<_version<<'('<<_version_date<<");\n";
        std::cout<<"Author:"<<_author<<";\n";
        std::cout<<"Email:"<<_author_email<<";\n";
        goto newcommand;
    };
    if(command=="help"){
        std::cout<<"Built-in commands:\n";
        for(int temp=0;temp<cmdnum;temp++) std::cout<<commands[temp].command_name<<";\n";
        goto newcommand;
    };
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