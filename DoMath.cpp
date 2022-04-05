//DoMath
//by james_sjk@126.com
//version 0.01
#define DOMATH
#define version 0.011

#include<iostream>
#include<fstream>
#include<bitset>
#include<ctime>
#include<cmath>

#include "structure.h"
#include "localtime.h"
#include "log.h"
#include "samkhya.h"
#include "ratio.h"
#include "rectcoord.h"

using namespace std;

bitset<32> bit32;


void writestr(string& route_and_name,string& text){
    ofstream fout(route_and_name);
    fout<<text;
    fout.close();
};



//——————————不怎么华丽的分割线——————————

int main(const int argc,const char* argv[]){
    using namespace std;
    
    ios::sync_with_stdio(false);
    cout<<"DoMath:"<<version<<"\n...is successfully running;\n";
    string argvstr[argc];
    if(argc!=0){
        register unsigned short count=0;
        do{
            argvstr[count]=argv[count];
            count++;
        }while(count<argc);
    }else if(argc==0){
        return 0;
    }
    cout<<argvstr[0]<<'\n';
    if(argc>1) cout<<argvstr[1]<<'\n';
    return 0;
}