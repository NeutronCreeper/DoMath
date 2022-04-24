#include<iostream>
#include "samkhya.h"
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    unsigned short count=0;
    char lenlimit=0;
    cout<<'{';
    for(long i=2;i<256;i++){
        if(prime(i)){
            cout<<i<<',';
            count++;
            if(lenlimit>=16){
                cout<<'\n';
                lenlimit=0;
            };
            lenlimit++;
        };
    }
    cout<<'}';
    cout<<endl;
    cout<<"Altogether: "<<count<<endl;
    return 0;
}