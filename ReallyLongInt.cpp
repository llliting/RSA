#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#include "ReallyLongInt.hpp"
#include <cmath>


using namespace std;
void ReallyLongInt::init(long long num){
    //update isNeg
    if(num >= 0)
        isNeg = false;
    else{
        isNeg = true;
        num *= -1;
    }
    //initialize and update size
    size = 16;
    unsigned int bits = (unsigned int) log2(num);
    while(bits >= size){
        size = size * 2;
    }
    //fill the digits
    digits = new vector<bool> (size, false);
    unsigned int index = 0;
    while(num > 0){
        if(num%2 == 1)
            (*digits)[index] = 1;
        num /= 2;
        index ++;
    }
}


ReallyLongInt::ReallyLongInt(){
    ReallyLongInt::init(0);
}

ReallyLongInt::ReallyLongInt(long long num){
    ReallyLongInt::init(num);
}

ReallyLongInt::ReallyLongInt(const string& numStr){
    ReallyLongInt::init(stoll(numStr));
}


ReallyLongInt::ReallyLongInt(const ReallyLongInt& other){
    size = other.size;
    digits = new vector<bool> (size, false);
    isNeg = other.isNeg;
    for(unsigned int i = 0; i < size; i ++)
        (*digits)[i] = (*(other.digits))[i];
}


ReallyLongInt::~ReallyLongInt(){
    delete digits;
}


bool ReallyLongInt::equal(const ReallyLongInt& other) const{
    if(isNeg != other.isNeg)
        return false;
    else if(size != other.size)
        return false;
    else{
        for(unsigned int i = 0; i < size; i ++)
            if((*digits)[i] != (*(other.digits))[i])
                return false;  
        return true;
    }
}

bool ReallyLongInt::absGreater(const ReallyLongInt& other) const{
    if(other.size > size)
        return 0;
    else if(other.size < size)
        return 1;
    else{
        for(unsigned int i = size - 1; i > 0; i --){
            if(((*digits)[i] == 1) && ((*(other.digits))[i] == 0))            
                return 1;
            else if(((*digits)[i] == 0) && ((*(other.digits))[i] == 1))
                return 0;
        }
        if(((*digits)[0] == 1) && ((*(other.digits))[0] == 0))
            return 1;
        return 0;
    }
    
}

bool ReallyLongInt::greater(const ReallyLongInt& other) const{
    if(isNeg == true && other.isNeg == false)
        return false;
    else if(isNeg == false && other.isNeg == true)
        return true;
    else 
        return (isNeg == true ? (!absGreater(other)) : absGreater(other));
}

string ReallyLongInt::toString() const{
    unsigned long long num = 0;
    for(unsigned int i = 0; i < size; i++)
        num += ( (*digits)[i] == 1 ? pow(2, i):0);
    return (isNeg ? ("-" + to_string(num)) : to_string(num));
}

string ReallyLongInt::toStringBinary() const{
    string str;
    for(unsigned int i = 0; i < size; ++i)
        str += ((*digits)[i] == 1 ? "1" : "0");        
    return str;
}


