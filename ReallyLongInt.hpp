
#ifndef REALLYLONGINT_H
#define REALLYLONGINT_H

#include <string>
#include <cmath>
#include <iostream>
#include <vector>
#include <cstring>
#include <string.h>

using namespace std;


class ReallyLongInt
{   
    //private:
    public:
        void init(long long num);
        vector<bool>* digits;
        unsigned int size;
        bool isNeg;
        bool absGreater(const ReallyLongInt& other) const;
        void swap(ReallyLongInt other);
        void flipSign();
        void absDiv (const ReallyLongInt& other, ReallyLongInt& quotient, ReallyLongInt& remainder) const;
        ReallyLongInt absMult(const ReallyLongInt& other) const;

        

   // public:
        ReallyLongInt();
        ReallyLongInt(long long num);
        ReallyLongInt(const string& numStr);
        ReallyLongInt(const ReallyLongInt& other);

        string toString() const;
        string toStringBinary() const;
        bool equal(const ReallyLongInt& other) const;
        bool greater(const ReallyLongInt& other) const;
        ~ReallyLongInt();

        void removeLeadingZeros(void);
        ReallyLongInt absAdd(const ReallyLongInt& other) const;
        ReallyLongInt add(const ReallyLongInt& other) const;
        ReallyLongInt absSub(const ReallyLongInt& other) const;
        ReallyLongInt sub(const ReallyLongInt& other) const;
        ReallyLongInt mult(const ReallyLongInt& other)const;
        void div (const ReallyLongInt& other, ReallyLongInt& quotient, ReallyLongInt& remainder) const;
        ReallyLongInt operator-() const;
        ReallyLongInt& operator=(const ReallyLongInt& other);



};
ReallyLongInt operator*(const ReallyLongInt& x, const ReallyLongInt& y);
ReallyLongInt operator/(const ReallyLongInt& x, const ReallyLongInt& y);
ReallyLongInt operator%(const ReallyLongInt& x, const ReallyLongInt& y);


#endif 