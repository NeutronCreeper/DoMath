#define SHELL

#include<iostream>
#include "headfile/_cmds.h"
#include "info.h"

int shell(const char* arg=""){
    std::cout<<arg<<"\nDoMath-shell<< start\n";
    newcommand:std::cout<<"DoMath-shell>> ";
    std::string command;
    std::cin>>command;
    if(command=="info"){
        std::cout<<"DoMath version: "<<_version<<'('<<_version_date<<")\n";
        std::cout<<"Author: "<<_author<<"(github: "<<_author_github<<")\n";
        std::cout<<"Email: "<<_author_email<<'\n';
        goto newcommand;
    };
    if(command=="help"){
        std::cout<<"Built-in commands:\n";
        for(int temp=0;temp<cmdnum;temp++) std::cout<<commands[temp].command_name<<";\n";
        goto newcommand;
        int temp=0;
    };
    for(int temp=0;temp<cmdnum;temp++){
        if(command.compare(commands[temp].command_name)==0){
            try{
                commands[temp].command_(0);
                goto newcommand;
            }catch(const char* msg){
                std::cerr<<msg;
                std::cin.clear();
                std::cin.ignore();
                goto newcommand;
            };
        };
    };
    std::cout<<command<<": unknown command!\n";
    std::cin.clear();
    std::cin.ignore();
    goto newcommand;
    return 0;
};