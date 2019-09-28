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
    removeLeadingZeros();
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
        num += ((*digits)[i] == 1 ? pow(2, i):0);
    return (isNeg ? ("-" + to_string(num)) : to_string(num));
}

string ReallyLongInt::toStringBinary() const{
    string str;
    for(unsigned int i = size - 1; i > 0; i--)
        str += ((*digits)[i] == 1 ? "1" : "0");  
    str  +=  ((*digits)[0] == 1 ? "1" : "0");  
    return str;
}







void ReallyLongInt::removeLeadingZeros(void){
    for(int i = size-1; i >= 0; i--){
        if((*digits)[i] == 1){
            this->size = i+1;
            break;
        }
        else if((i == 0) && ((*digits)[0] == 0))
            this->size = 1;
        else if((i == 0) && ((*digits)[0] == 1))
            return;
    }
    vector<bool>* newDigits = new vector<bool> (size, false); 
    for(unsigned int i = 0; i < size; i ++)
        (*newDigits)[i] = (*digits)[i];
    delete digits;
    this->digits = newDigits;
}

void ReallyLongInt::swap(ReallyLongInt other){
    std::swap(this->digits,other.digits);
	std::swap(this->isNeg,other.isNeg);
	std::swap(this->size,other.size);
}

ReallyLongInt& ReallyLongInt::operator=(const ReallyLongInt& other){
    swap(other);
    return *this;
}

void ReallyLongInt::flipSign(){
    if(toString() == "0")
        isNeg = false;
    else 
        isNeg = (isNeg == true ? false : true);
}

ReallyLongInt ReallyLongInt::operator-() const{
    ReallyLongInt flip = *this;
    flip.flipSign();
    return flip;
}

ReallyLongInt ReallyLongInt::absAdd(const ReallyLongInt& other) const{
    int carry = 0;
    ReallyLongInt ans;
    ans.size = (size > other.size ? size : other.size) + 1;
    delete ans.digits;
    ans.digits = new vector<bool> (ans.size, false); 
    ans.isNeg = false;
    unsigned int i = 0;
    for(; i < ans.size ; i ++){
        (*ans.digits)[i] = carry ^ (*digits)[i] ^ (*(other.digits))[i];
        if((((*digits)[i] & (*other.digits)[i]) == 1) 
            || ((carry & (*(other.digits))[i]) == 1) 
            || (((*digits)[i] & carry ) == 1))
            carry = 1;
        else
            carry = 0;
    }
    if(carry == 1) 
        (*ans.digits)[i] = 1;
    ans.removeLeadingZeros();
    return ans;
}

ReallyLongInt ReallyLongInt::absSub(const ReallyLongInt& other) const{
    ReallyLongInt ans;
    vector<bool>* larger;
    vector<bool>* smaller;
    if(equal(other) || equal(-other))
      return ReallyLongInt(0);
    ans.isNeg = absGreater(other) ? false : true;
    if(ans.isNeg){
        larger = other.digits;
        smaller = this->digits;
        ans.size = other.size;
    }
    else{
        larger = this->digits;
        smaller = other.digits;
        ans.size = this->size;
    }
    delete ans.digits;
    ans.digits = new vector<bool> (ans.size, false);
    int borrow = 0;
    for(unsigned int i = 0; i < ans.size; i ++){
        if((*larger)[i] == 1 && (*smaller)[i] == 0){
            (*ans.digits)[i] = 1 - borrow;
            borrow = 0;
        }
        else if(((*larger)[i] == (*smaller)[i])){
            (*ans.digits)[i] = (borrow == 0 ? 0 : 1);
        }
        else{
            (*ans.digits)[i] = (borrow == 0 ? 1 : 0);
            borrow = 1;
        }
     }
    ans.removeLeadingZeros();
    return ans;
}

ReallyLongInt ReallyLongInt::add(const ReallyLongInt& other) const{
    if(isNeg == other.isNeg) 
        return isNeg ? -absAdd(other) : absAdd(other);
    else 
        return isNeg ? other.absSub(*this) : absSub(other);
}

ReallyLongInt ReallyLongInt::sub(const ReallyLongInt& other) const{
    if(isNeg == other.isNeg)
        return isNeg ? -absSub(other) : absSub(other);
    else 
        return isNeg ? -absAdd(other) : absAdd(other);
}

ReallyLongInt ReallyLongInt::absMult(const ReallyLongInt& other) const{
    vector<bool>* ans = new vector<bool> (size + other.size, false);
    bool mul;
    for(unsigned int i = 0; i < size; i ++){
        for(unsigned int j = 0; j < other.size; j ++){
            mul = (*digits)[i] & (*other.digits)[j];
            if(mul && (*ans)[i+j]){
                if( (*ans)[i+j+1] == 1){
                    (*ans)[i+j+1] = 0;
                    (*ans)[i+j+2] = 1;
                }
                else
                    (*ans)[i+j+1] = 1;
            }
            (*ans)[i + j] = ( mul ^ (*ans)[i + j]);
        }
    }
    ReallyLongInt answer;
    answer.size = size + other.size;
    delete answer.digits;
    answer.digits = ans;
    answer.removeLeadingZeros();
    return answer; 
}

ReallyLongInt ReallyLongInt::mult(const ReallyLongInt& other)const{
    if(isNeg == other.isNeg)
        return absMult(other);
    else 
        return -absMult(other);
}

void ReallyLongInt::absDiv (const ReallyLongInt& other, ReallyLongInt& quotient, ReallyLongInt& remainder) const{
    ReallyLongInt r;    
    ReallyLongInt d;
    ReallyLongInt q;
    int helper = pow(2,size);
    for(int i = size-1; i >= 0; i --){
        r = r * 2;
        if((*digits)[i] == 1) 
            r = r + 1;
        d = 0;
        while(r.greater(other) || r.equal(other)){
            r = r - other;
            d = d + 1;
        }
    helper /= 2;
    d = d * helper;
    q = q + d;
    }
    quotient = q;
    remainder = r;
}

void ReallyLongInt::div (const ReallyLongInt& other, ReallyLongInt& quotient, ReallyLongInt& remainder) const{
    absDiv(other, quotient, remainder);
    if(isNeg != other.isNeg)
        quotient = -quotient;
}


ReallyLongInt operator*(const ReallyLongInt& x, const ReallyLongInt& y){
    return x.mult(y);
}

ReallyLongInt operator+(const ReallyLongInt& x, const ReallyLongInt& y){
    return x.add(y);
}

ReallyLongInt operator-(const ReallyLongInt& x, const ReallyLongInt& y){
    return x.sub(y);
}

ReallyLongInt operator/(const ReallyLongInt& x, const ReallyLongInt& y){
    ReallyLongInt q;
    ReallyLongInt r;
    x.div(y, q, r);
    return q;
}

ReallyLongInt operator%(const ReallyLongInt& x, const ReallyLongInt& y){
    ReallyLongInt q;
    ReallyLongInt r;
    x.div(y, q, r);
    return r;
}








ReallyLongInt ReallyLongInt::recurExpo(const ReallyLongInt& e) const{
    if(e == 0)
        return ReallyLongInt(1);
    else if((*e.digits)[0])
        return (*this) * recurExpo(e/2) * recurExpo(e/2);
    else
        return recurExpo(e/2) * recurExpo(e/2);
}

ReallyLongInt ReallyLongInt::exponent(const ReallyLongInt& e)const{
    return recurExpo(e);
}


bool ReallyLongInt::isPrime() const{
    if(*this <= 3) //1,2,3
        return true;
    else if(!(*digits)[0]) // even number
        return false;
    else 

}



bool operator==(const ReallyLongInt& x, const ReallyLongInt& y){
    return x.equal(y);
}

bool operator<(const ReallyLongInt& x, const ReallyLongInt& y){
    return y.greater(x);
}

bool operator>(const ReallyLongInt& x, const ReallyLongInt& y){
    return x.greater(y);
}

bool operator<=(const ReallyLongInt& x, const ReallyLongInt& y){
    return (x<y)||(x==y); 
}

bool operator>=(const ReallyLongInt& x, const ReallyLongInt& y){
    return (y<x)||(x==y); 
}














int main(){
    //long long a;
    //long long b;
    //printf("a: ");
    //cin >> a;
    //printf("b : ");
    //cin >> b;
    //ReallyLongInt x(a);
    //ReallyLongInt y(b);
    
   // bool z = (x>y);
    //cout << z << endl;
    //cout << x.toStringBinary() << endl;
    //ReallyLongInt ans = x.exponent(y);
    //ReallyLongInt y = -x;
    //cout << "ans: " << ans.toString() << endl;
    
   // ReallyLongInt d;
     //c = c + d ;
    ///cout << "q: " << q.toString() << endl;
    //cout << "r: " << r.toString() << endl;
}

