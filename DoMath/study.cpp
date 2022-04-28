#include<iostream>
#include "headfile/prime/prime.h"




int main(){
    long max=0;
    for(int p=2;p<111;p++){
        if(!prime(p)) continue;
        for(int q=2;q<111;q++){
            if(!prime(q)) continue;
            for(int r=2;r<32000;r++){
                if(!prime(r)) continue;
                if(
                    ((p+q)/r==p-q+r)
                    &&(p+q<111)
                    &&((p+q)%r==0)
                ){
                    printf("(%d,%d,%d),%d;\n",p,q,r,p*q*r);
                    if(p*q*r>max) max=p*q*r;
                }
            }
        }
    }
    printf("\n%ld;\n",max);
    return 0;
};