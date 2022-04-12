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

string levels[6]={"debug","fatal","error","warn ","note ","info "};

#ifdef LOG_do
ofstream Programlog(timeString()+" DoMathLog.txt");
void logw(string text,char level,string tag="DoMath"){
    refreshTime();
    Programlog<<1900+CurrentLocalTime->tm_year<<CurrentLocalTime->tm_mon+1<<CurrentLocalTime->tm_mday<<'-'<<CurrentLocalTime->tm_hour<<':'<<CurrentLocalTime->tm_min<<':'<<CurrentLocalTime->tm_sec;
    string l=levels[level];
    Programlog<<'<'<<tag<<'>'<<'['<<l<<']'<<text<<'\n';
};
#ifdef DOMATH_version
void sayhello(){
    string hello="DoMath:"+to_string(DOMATH_version)+"\n...is successfully running;\n...on "+timeString()+";\n";
    logw(hello,info);
};
#endif
#endif



void write_str_to_file(string& route_and_name,string& text){
    ofstream fout(route_and_name);
    fout<<text;
    fout.close();
};