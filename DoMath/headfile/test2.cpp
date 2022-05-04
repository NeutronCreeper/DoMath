#include<iostream>
#include "function/monomial.h"
using namespace std;
int main(){
    algebra a(3,"a1");
    exponential e(&a,3);
    cout<<e<<endl;
    return 0;
}