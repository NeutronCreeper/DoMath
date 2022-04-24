#define DOMATH
#define DOMATH_version 0.011



#include "including.h"
#include "setting.h"
#include "shell.h"

using namespace std;



#define LOG_donot


////////////////////////////////////////////////////////////////


int main(const int argc,const char* argv[]){
    using namespace std;
    cout<<"DoMath:"<<DOMATH_version<<"\n...is successfully running;\n";
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
    cout<<"at "<<argvstr[0]<<',';
    if(argc>1) cout<<argvstr[1]<<";\n";
    shell();
    return 0;
}