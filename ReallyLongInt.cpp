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

ReallyLongInt::ReallyLongInt(long long num){
    //update isNeg
    if(num >= 0)
        isNeg = false;
    else{
        isNeg = true;
        num *= -1;
    }
    //initialize and update size
    size = 16;
    long long max = 1 << size;
    while(num >= max){
        max = max << size;
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

ReallyLongInt::~ReallyLongInt(){
    delete digits;
}


bool ReallyLongInt::equal(const ReallyLongInt& other) const{
    if(isNeg != other.isNeg)
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
        for(unsigned int i = size - 1; i >= 0; i --){
            if(((*digits)[i] == 1) && ((*(other.digits))[i] == 0))            
                return 1;
            else if(((*digits)[i] == 0) && ((*(other.digits))[i] == 1))
                return 0;
        }
        return 0;
    }
    
}

bool ReallyLongInt::greater(const ReallyLongInt& other) const{
    if(isNeg == true && other.isNeg == false)
        return false;
    else if(isNeg == false && other.isNeg == true)
        return true;
    else 
        return (isNeg == true ? !absGreater(other) : absGreater(other));
}


string ReallyLongInt::toString() const{
    long long num = 0;
    for(unsigned int i = 0; i < size; i++){
        num += ( (*digits)[i] == 1 ? pow(2, i):0);
    }
    return (isNeg ? ("-" + to_string(num)) : to_string(num));
}

string ReallyLongInt::toStringBinary() const{
    string str;
    for(unsigned int i = 0; i < size; ++i)
        str += ((*digits)[i] == 1 ? "1" : "0");        
    return str;
}


int main(){
    long long x, y;
    cout << "type in a number : ";
    cin >> x;
    ReallyLongInt a(x);
    cout << "type in a number : ";
    cin >> y;
    ReallyLongInt b(y);
    cout << a.size << " " << (*(a.digits))[0] << " " << a.isNeg << endl;
    cout << "greater" << a.absGreater(b)<< endl;
    cout << a.toStringBinary() << endl;
    cout << a.toString() << endl;
    return 0;
}


