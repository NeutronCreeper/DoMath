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

using namespace std;
ofstream Programlog(timeString()+" DoMathLog.txt");
void logw(string& text,string tag="DoMath"){
    refreshTime();
    Programlog<<1900+CurrentLocalTime->tm_year<<CurrentLocalTime->tm_mon+1<<CurrentLocalTime->tm_mday<<'-'<<CurrentLocalTime->tm_hour<<':'<<CurrentLocalTime->tm_min<<':'<<CurrentLocalTime->tm_sec;
    Programlog<<'['<<tag<<']'<<text<<'\n';
};