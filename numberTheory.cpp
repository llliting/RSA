#include "numberTheory.hpp"
#include "ReallyLongInt.hpp"



using namespace std;




ReallyLongInt numberTheory::extendedEuclid(const ReallyLongInt& a, const ReallyLongInt& b, 
                            ReallyLongInt& x, ReallyLongInt& y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    else{
       ReallyLongInt output_x;
       ReallyLongInt output_y;
       ReallyLongInt d = extendedEuclid(b, a%b, output_x, output_y);
       x = output_y;
       y = output_x - (output_y * (a / b));
       return d;
    }
}
