
#ifndef REALLYLONGINT_H
#define REALLYLONGINT_H

#include <string>
#include <math.h>
#include <iostream>
#include <vector>
#include <bitset>
#include <string.h>

using namespace std;


class ReallyLongInt
{
    public:
   //private:
        vector<bool>* digits;
        unsigned int size;
        bool isNeg;
        bool absGreater(const ReallyLongInt& other) const;
        void init(long long num);
        

    //public:
        ReallyLongInt();
        ReallyLongInt(long long num);
        ReallyLongInt(const string& numStr);
        ReallyLongInt(const ReallyLongInt& other);

        string toString() const;
        string toStringBinary() const;
        bool equal(const ReallyLongInt& other) const;
        bool greater(const ReallyLongInt& other) const;
        ~ReallyLongInt();
};

#endif 