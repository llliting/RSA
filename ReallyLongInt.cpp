#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include "ReallyLongInt.hpp"
#include <cmath>

using namespace std;

ReallyLongInt::ReallyLongInt(){
    size = 16;
    digits = new vector<bool> (16, false);
    isNeg = false;
}

ReallyLongInt::~ReallyLongInt(){
    delete digits;
}

string ReallyLongInt::toString() const{
    
}

string ReallyLongInt::toBinaryString() const{
    
}






int main(){
    ReallyLongInt a;
    cout << a.size << " " << (*(a.digits))[0] << " " << a.isNeg << endl;
    return 0;
}


