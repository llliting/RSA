
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
    private:
        void init(long long num);
        vector<bool>* digits;
        unsigned int size;
        bool isNeg;
        bool absGreater(const ReallyLongInt& other) const;
        

    public:
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
        void swap(ReallyLongInt other);
        ReallyLongInt& operator=(const ReallyLongInt& other);
        ReallyLongInt absAdd(const ReallyLongInt& other) const;
        ReallyLongInt add(const ReallyLongInt& other) const;
        
};

#endif 