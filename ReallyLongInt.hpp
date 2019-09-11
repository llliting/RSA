//#ifndef ReallyLongInt
#define ReallyLongInt

#include <iostream>
#include <vector>
#include <string.h>


class ReallyLongInt{
    public:
        ReallyLongInt();
        ReallyLongInt(long long num);
        ReallyLongInt(const string& numStr);
        ReallyLongInt(const ReallyLongInt& other);
        string toString() const;
        string toStringBinary() const;
        ~ReallyLongInt();
};
