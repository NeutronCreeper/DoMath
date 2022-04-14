#define LOG

#ifndef iostream
#include<iostream>
#endif
#ifndef ctime
#include<ctime>
#endif
#ifndef fstream
#include<fstream>
#endif

#ifndef LOCALTIME
#include "localtime.h"
#endif

#define debug ((char)0)
#define fatal ((char)1)
#define error ((char)2)
#define warn ((char)3)
#define note ((char)4)
#define info ((char)5)
using namespace std;

const string levels[6]={"debug","fatal","error","warn ","note ","info "};

#ifdef log_do
ofstream Programlog("DoMathLog.txt",ios::app);
void logw(string text,char level,string tag="DoMath"){
    string l=levels[level];
    Programlog<<'<'<<tag<<'>'<<'['<<l<<"](";
    refreshTime();
    Programlog<<timeString();
    Programlog<<"): "<<text<<";\n";
};
void log_start(){
    logw("\n\n\n\nDoMath program started at "+timeString(),info);
};
#endif



void write_str_to_file(string& route_and_name,string& text){
    ofstream fout(route_and_name,ios::app);
    fout<<text;
    fout.close();
};