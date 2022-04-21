#include<iostream>
using namespace std;

#include "ratio.h"
#include "rectcoord.h"

int main(){
    chain<ratio> rc(ratio(1,3));
    rc+=ratio(1,2);
    rc.print(std::cout);
    return 0;
}