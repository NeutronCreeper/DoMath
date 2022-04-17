#define RAD

#ifndef iostream
#include<iostream>
#endif
#ifndef RATIO
#include "ratio.h"
#endif
#ifndef REAL
#include "real.h"
#endif

class rad{
    private:
    ratio value;
    public:
    inline rad(ratio b=ratio(1,4)){
        value=b;
    };
    void operator=(const rad& b){
        value=b.value;
    };
    void operator+=(const rad& b){
        value+=b.value;
    };
    void operator-=(const rad& b){
        value-=b.value;
    };
    rad operator+(const rad& b){
        return rad(this->value+b.value);
    };
    rad operator-(const rad& b){
        return rad(this->value-b.value);
    };
    bool operator==(const rad& b){
        return value==b.value;
    };
    bool operator>(const rad& b){
        return value>b.value;
    };
    bool operator<(const rad& b){
        return value<b.value;
    };
    friend std::ostream& operator<<(std::ostream& output,const rad& b){
        output<<b.value<<"PI";
        return output;
    };
    real_single sin(){
        return real_single();
    };
};