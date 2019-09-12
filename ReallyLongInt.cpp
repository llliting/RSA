#include <iostream>
#include <vector>
#include <string.h>
#include "ReallyLongInt.hpp"

using namespace std;


ReallyLongInt::ReallyLongInt(){
    size = 16;
    vector<bool> newNum;
    newNum.push_back(0);
    digits[0] = newNum;
}



bool ReallyLongInt::greater(const ReallyLongInt& other) const{
    return true;
}


int main(){
    return 0;
}

