#include<iostream>
#include ".common/structure/chain.h"
#include ".common/lazy.h"
using namespace std;
int main(){
    chain<int> a;
    a+=1;
    a+=2;
    a+=3;
    a+=4;
    a.print();
    cout<<endl;
    system("pause");
    // chain<int> b(2);
    // b+=3;
    // b+=5;
    // (a||b).print();
    // cout<<endl;
    system("pause");
    a([&](int& a)->void{a=7;});
    a.print();
    return 0;
}