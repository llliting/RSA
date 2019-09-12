#include <iostream>
#include <vector>
#include <string.h>
#include <sstream>
#include "ReallyLongInt.hpp"


using namespace std;


ReallyLongInt::ReallyLongInt(){
    size = 16;
    vector<bool> newNum;
    newNum.push_back(0);
    digits[0] = newNum;
}

ReallyLongInt::ReallyLongInt(long long num){

}


string ReallyLongInt::toString() const{
    for(auto&& i : digits[0])
    return 
}


bool ReallyLongInt::greater(const ReallyLongInt& other) const{
    return true;
}


int main(){
    ReallyLongInt x;
    cout << x << endl;
    return 0;
}

