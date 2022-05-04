#define _CMDS_RECTCOORD
//built-in commands for "rectcoord.h"
#include<iostream>
#ifndef RECTCOORD
#include "rectcoord.h"
#endif
#ifndef RATIO
#include "../ratio/ratio.h"
#endif
namespace rectcoord_cmds{

void solveline(int flag){
    std::cout<<"Please type in the type of 2 points;\n'i' for <int>, 'f' for <float>, 'r' for <ratio>, 'R' for <real>;\n";
    char ch;
    std::cin>>ch;
    std::cout<<"Please type in coordinates of 2 points;\n";
    if(ch=='i'){
        int a,b,c,d;
        std::cin>>a>>b>>c>>d;
        if(!std::cin.good()) throw "Bad input!\n";
        point<int> A(a,b),B(c,d);
        std::cout<<"Formula of line \"(noname)\" is: "<<solve_from_point(A,B)<<";\n";
    }else if(ch=='f'){
        float a,b,c,d;
        std::cin>>a>>b>>c>>d;
        if(!std::cin.good()) throw "Bad input!\n";
        point<float> A(a,b),B(c,d);
        std::cout<<"Formula of line \"(noname)\" is: "<<solve_from_point(A,B)<<";\n";
    }else if(ch=='r'){
        short a,b,c,d,e,f,g,h;
        ratio A(a,b),B(c,d),C(e,f),D(g,h);
        if(!std::cin.good()) throw "Bad input!\n";
        point<ratio> p1(A,B),p2(C,D);
        std::cout<<"Formula of line \"(noname)\" is: "<<solve_from_point(p1,p2)<<";\n";
    };
};

void solvepoint(int flag){
    std::cout<<"Please type in the type of 2 lines;\n'i' for <int>, 'f' for <float>, 'r' for <ratio>, 'R' for <real>;\n";
    char c;
    std::cin>>c;
    std::cout<<"Please type in formulas of 2 lines;\n";
    if(c=='i'){
        int a,b,c,d;
        std::cin>>a>>b>>c>>d;
        if(!std::cin.good()) throw "Bad input!\n";
        line<int> A(a,b),B(c,d);
        std::cout<<"Coordinate of point \"(noname)\" is: "<<solve_from_line(A,B)<<";\n";
    }else if(c=='f'){
        float a,b,c,d;
        std::cin>>a>>b>>c>>d;
        if(!std::cin.good()) throw "Bad input!\n";
        line<float> A(a,b),B(c,d);
        std::cout<<"Coordinate of point \"(noname)\" is: "<<solve_from_line(A,B)<<";\n";
    }else if(c=='r'){
        ratio a,b,c,d;
        std::cin>>a>>b>>c>>d;
        if(!std::cin.good()) throw "Bad input!\n";
        line<ratio> A(a,b),B(c,d);
        std::cout<<"Coordinate of point \"(noname)\" is: "<<solve_from_line(A,B)<<";\n";
    };
};

}