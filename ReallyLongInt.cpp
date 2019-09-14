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
    long long num = 0;
    for(size_t i = 0; i < size; i++){
        num += ( (*digits)[i] == 1 ? pow(2, i):0);
    }
    return (isNeg ? ("-" + to_string(num)) : to_string(num));
}

string ReallyLongInt::toStringBinary() const{
    string str;
    for(size_t i = 0; i < size; ++i)
        str += ((*digits)[i] == 1 ? "1" : "0");        
    return str;
}


int main(){
    ReallyLongInt a;
    cout << a.size << " " << (*(a.digits))[0] << " " << a.isNeg << endl;
    cout << a.toStringBinary() << endl;
    cout << a.toString() << endl;
    return 0;
}


