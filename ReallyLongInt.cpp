#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include <bitset>
#include "ReallyLongInt.hpp"

using namespace std;


ReallyLongInt::ReallyLongInt(){
    size = 16;
    vector<bool> newNum(size,false);
    digits = &newNum;
    isNeg = false;
}

ReallyLongInt::ReallyLongInt(long long num){
    //update size
    long long max = 1 << size;
    while(num >= max){
        max = max << size;
        size = size * 2;
    }

    //update isNeg
    if(num >= 0)
        isNeg = false;
    else
        isNeg = true;

  /*  
    //calculate the bits of num
    int bits = 0;
    int currSum = 1;
    while(currSum <= num){
        currSum *= 2;
        bits ++;
    }


    //create the vector
    vector<bool> newNum(size-bits, false);
    digits = &newNum;

    //fill the vector
    while(num != 0){
        if(num%2 == 1)
            newNum.push_back(true);
        else
            newNum.push_back(false);
        num /= 2;
    }
    */
}


ReallyLongInt::ReallyLongInt(const string &numStr){
    ReallyLongInt(stoll(numStr));
}

ReallyLongInt::ReallyLongInt(const ReallyLongInt &other){
    //vector<bool> copy(other);
}

int ReallyLongInt::getSize(){
    return size;
}

string ReallyLongInt::toString() const{
    string myStr;
    for(size_t i = 0; i < size; ++i){
        myStr.push_back(*digits[i]);
    }

    return myStr;
    
}

/*
string ReallyLongInt::toStringBinary() const{
    char string[size];
    for(size_t i = 0; i < size; i++){
        string[i] = *digits[i];
    }
}
*/


bool ReallyLongInt::greater(const ReallyLongInt& other) const{
    return true;

}


int main(){
    ReallyLongInt* x = new ReallyLongInt(100000);
    cout << x->getSize() << endl;
    //cout << x << endl;
    return 0;
}
