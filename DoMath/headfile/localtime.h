#define LOCALTIME

#ifndef iostream
#include<iostream>
#endif
#ifndef ctime
#include<ctime>
#endif

time_t now=time(0);
tm* CurrentLocalTime=localtime(&now);

inline void refreshTime(){
    now=time(0);
    CurrentLocalTime=localtime(&now);
};
std::string timeString(){
    refreshTime();
    return std::to_string(CurrentLocalTime->tm_year+1900)
    +'-'+std::to_string(CurrentLocalTime->tm_mon+1)
    +'-'+std::to_string(CurrentLocalTime->tm_mday)
    +", "+std::to_string(CurrentLocalTime->tm_hour)
    +':'+std::to_string(CurrentLocalTime->tm_min);
};