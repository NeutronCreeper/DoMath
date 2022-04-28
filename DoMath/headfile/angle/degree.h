#define DEGREE

#include<iostream>

template<typename data>class degree{
    private:
    data value;
    public:
    inline degree(const data& v=0){
        value=v;
    };
    inline degree(const short v=0){
        value=v;
    };
    inline degree(const degree<data>& v){
        value=v.value;
    };
    void operator=(const degree<data>& v){
        value=v.value;
    };
    void operator=(const data& v){
        value=v;
    };
    void operator=(const short v){
        value=v;
    };
    bool operator==(const degree<data>& v){
        return value==v.value;
    };
    bool operator==(const data& v){
        return value==v;
    };
    bool operator==(const short v){
        return value==v;
    };
    degree<data> operator-(){
        return degree<data>(-value);
    };
    void operator+=(const degree<data>& v){
        value+=v.value;
    };
    void operator+=(const data& v){
        value+=v;
    };
    void operator+=(const short v){
        value+=v;
    };
    void operator-=(const degree<data>& v){
        value-=v.value;
    };
    void operator-=(const data& v){
        value-=v;
    };
    void operator-=(const short v){
        value-=v;
    };
    degree<data> operator+(const degree<data>& v){
        return degree<data>(value+v.value);
    };
    degree<data> operator+(const data& v){
        return degree<data>(value+v);
    };
    degree<data> operator+(const short v){
        return degree<data>(value+v);
    };
    degree<data> operator-(const degree<data>& v){
        return degree<data>(value-v.value);
    };
    degree<data> operator-(const data& v){
        return degree<data>(value-v);
    };
    degree<data> operator-(const short v){
        return degree<data>(value-v);
    };
};