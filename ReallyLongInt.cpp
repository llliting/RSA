#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include "ReallyLongInt.hpp"

using namespace std;


ReallyLongInt::ReallyLongInt(){
    size = 16;
    vector<bool> newNum(size);
    digits = &newNum;
    isNeg = false;
}

ReallyLongInt::ReallyLongInt(long long num){
    //update size
    while(num >= 1<<size){
        size = size * 2;
    }

    //update isNeg
    if(num >= 0)
        isNeg = false;
    else
        isNeg = true;

    //create the vector
    vector<bool> newNum(size, false);
    digits = &newNum;


    //calculate the bits of num
    int bits = 0;
    int currSum = 1;
    while(currSum <= num){
        currSum *= 2;
        bits ++;
    }

    //fill the vector
    int i = size - bits;
    while(num != 0){
        if(num%2 == 1)
            newNum[i] = true;
        else
            newNum[i] = false;
        i ++;
        num /= 2;
    }
}


ReallyLongInt::ReallyLongInt(const string &numStr){
    ReallyLongInt(stoll(numStr));
}

ReallyLongInt::ReallyLongInt(const ReallyLongInt &other){
    //vector<bool> copy(other);

}



string ReallyLongInt::toString() const{
    return "";
    
}


bool ReallyLongInt::greater(const ReallyLongInt& other) const{
    return true;

}


int main(){
    ReallyLongInt x;
    //cout << x << endl;
    return 0;
}

