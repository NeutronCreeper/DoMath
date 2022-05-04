#define ALGEBRA

#include<iostream>
#include<vector>


struct algebra{
    long id=0;
    std::string name;
    inline algebra(const long& id_,const char* name_){
        id=id_;
        name=name_;
    };
    inline algebra(const long& id_,std::string name_){
        id=id_;
        name=name_;
    };
    bool operator==(const algebra& a){
        return id==a.id;
    };
    bool operator!=(const algebra& a){
        return id!=a.id;
    };
};