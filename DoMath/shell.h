#define SHELL

#include<iostream>
#include<string.h>
#include "headfile/_cmds.h"
#include "info.h"




int shell(const char* arg=""){
    printf("%s\nDoMath-shell<< start\n",arg);
    newcommand:;
    printf("DoMath-shell>> ");
    std::string command;
    std::cin>>command;
    if(command=="info"){
        printf("DoMath version: %s(%s);\n",_version,_version_date);
        printf("Author: %s\n",_author);
        printf("Email: %s\n",_author_email);
        goto newcommand;
    };
    if(command=="help"){
        printf("Built-in commands:\n");
        for(int temp=0;temp<cmdnum;temp++) printf("%s;\n",commands[temp].command_name.c_str());
        goto newcommand;
        int temp=0;
    };
    for(int temp=0;temp<cmdnum;temp++){
        if(command.compare(commands[temp].command_name)==0){
            try{
                commands[temp].command_(0);
                goto newcommand;
            }catch(const char* msg){
                perror(msg);
                printf("Command failed to execute.\n");
                std::cin.clear();
                std::cin.ignore();
                goto newcommand;
            };
        };
    };
    printf("%s: Unknown command!\n",command.c_str());
    std::cin.clear();
    std::cin.ignore();
    goto newcommand;
    return 0;
};