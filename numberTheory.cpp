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
       cout << "x: " << x.toString() << " y: " << y.toString() << endl;
       //ReallyLongInt temp = x;
       x = output_y;
       y = output_x - (output_y * (a / b));
       return d;
    }
}
/*
int main(){
    long long atemp, btemp;
    cout << "a: " ;
    cin >> atemp;
    cout << "b: ";
    cin >> btemp;
    ReallyLongInt a (atemp);
    ReallyLongInt b (btemp);
    ReallyLongInt x, y;
    numberTheory nt;
    ReallyLongInt ans = nt.extendedEuclid(a, b, x, y);
    cout << "ans: " << ans.toString() << endl;
    cout << "x: " << x.toString() << endl;
    cout << "y: " << y.toString() << endl;


}
*/