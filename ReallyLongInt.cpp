#include <iostream>
#include <vector>
#include <string.h>
#include "ReallyLongInt.hpp"

using namespace std;


ReallyLongInt::ReallyLongInt(){
    size = 1;
    digits[0] = new vector<bool>(0); 
}



bool ReallyLongInt::greater(const ReallyLongInt& other) const{
    return true;
}
