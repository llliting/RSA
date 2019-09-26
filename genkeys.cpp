//#include "ReallyLongInt.hpp"
#include "ReallyLongInt.cpp"

#include <iostream>

using namespace std;

int main(){
    ReallyLongInt p;
    ReallyLongInt q;
    ReallyLongInt n = p * q;
    ReallyLongInt t = (p-1) * (q-1);
    ReallyLongInt e = t - 1;
    while(e.greater(1)){
        if(!(t%e).equal(0))
            break;
        e = e - 1;
    }

    ReallyLongInt d;
    



}