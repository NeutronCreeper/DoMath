#define DOMATH


#include "including.h"
#include "setting.h"
#include "shell.h"

#define LOG_donot


////////////////////////////////////////////////////////////////


int main(const int argc,const char* argv[]){
    using namespace std;
    ios::sync_with_stdio(false);
    cout<<"DOMATH\n";
    string argvstr[argc];
    if(argc!=0){
        unsigned short count=0;
        do{
            argvstr[count]=argv[count];
            count++;
        }while(count<argc);
    }else if(argc==0){
        return 0;
    };
    shell();
    return 0;
}