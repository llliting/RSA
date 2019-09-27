#include "numberTheory.hpp"

using namespace std;

std::tuple <ReallyLongInt, ReallyLongInt, ReallyLongInt> extendedEulid(const ReallyLongInt& a, const ReallyLongInt& b){
    ReallyLongInt x, y, d, xTemp, yTemp;
    if(b == 0){
        x = ReallyLongInt(1);
        y = ReallyLongInt(0);
        return std::tuple <ReallyLongInt, ReallyLongInt, ReallyLongInt>(a, x, y);
    }
    else{
        std::tuple <ReallyLongInt, ReallyLongInt, ReallyLongInt>(a, x, y) = extendedEulid(b, a%b);
        xTemp = y;
        yTemp = x- (y * (a/b));
    }
    return std::tuple <ReallyLongInt, ReallyLongInt, ReallyLongInt>(d, xTemp, yTemp);
}