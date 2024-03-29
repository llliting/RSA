#ifndef NUMBERTHEORY_H
#define NUMBERTHEORY_H

#include "ReallyLongInt.cpp"
#include "ReallyLongInt.hpp"

using namespace std;


class numberTheory
{   
    public: 
    ReallyLongInt extendedEuclid(const ReallyLongInt& a, const ReallyLongInt& b, 
                            ReallyLongInt& x, ReallyLongInt& y);
};

#endif