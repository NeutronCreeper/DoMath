#define PARABOLA_CMDS
//built-in commands for "parabola.h"
#ifndef PARABOLA
#include "parabola.h"
#endif

namespace parabola_cmds{

void solveparabola(int flag){
    std::cout<<"Please type in the type of 3 points;\n";
    std::cout<<"'f' for <float>, 'R' for <real>;\n";
    char ch;
    std::cin>>ch;
    if(std::cin.good()){
        if(ch=='R'){
            std::cout<<"To be developed!\n";
        }else if(ch=='f'){
            std::cout<<"Please type in coordinates of 3 points;\n";
            float a,b,c,d,e,f;
            std::cin>>a>>b>>c>>d;
            if(std::cin.good()){
                parabola<float> ans;
                point<float> A(a,b),B(c,d),C(e,f);
                ans.solve_from_point(A,B,C);
                std::cout<<"Formula of parabola \"(noname)\" is: "<<ans<<";\n";
            }else{
                throw "Not legal numbers!\n";
            };
        }else{
            throw "Not supported argument type expression!\n";
        };
    }else{
        throw "Not legal argument type!\n";
    };
};

void toppoint(int flag){
    std::cout<<"Please type in the type of the parabola;\n";
    std::cout<<"'f' for <float>, 'R' for <real>;\n";
    char ch;
    std::cin>>ch;
    if(std::cin.good()){
        if(ch=='R'){
            std::cout<<"To be developed!\n";
        }else if(ch=='f'){
            std::cout<<"Please type in the formular of a parabola;\n";
            std::cout<<"{y=ax^2+bx+c}, type in (a,b,c);\n";
            float a,b,c;
            std::cin>>a>>b>>c;
            if(std::cin.good()){
                parabola<float> p(a,b,c);
                std::cout<<"Toppoint of this parabola is "<<p.top()<<";\n";
            }else{
                throw "Not legal numbers!\n";
            };
        }else{
            throw "Not supported argument type expression!\n";
        };
    }else{
        throw "Not legal argument type!\n";
    };
};

}