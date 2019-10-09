#include "numberTheory.hpp"
#include "ReallyLongInt.hpp"



using namespace std;




ReallyLongInt numberTheory::extendedEuclid(const ReallyLongInt& a, const ReallyLongInt& b, 
                            ReallyLongInt* output_x, ReallyLongInt* output_y){
    if(b == 0){
        *output_x = ReallyLongInt(1);
        *output_y = ReallyLongInt(0);
        cout << "x: " << output_x->toString() << endl;
       cout << "y: " << output_y->toString() << endl;
        return a;
    }
    else{
       ReallyLongInt d = extendedEuclid(b, a%b, output_x, output_y);
       ReallyLongInt temp = *output_x;
       *output_x = *output_y;
       *output_y = temp - ((*output_y) * (a / b));
       cout << "x: " << output_x->toString() << endl;
       cout << "y: " << output_y->toString() << endl;
       cout << "\n";
       return d;
    }
}
/*
int main(){
    ReallyLongInt* x = new ReallyLongInt();
    ReallyLongInt* y = new ReallyLongInt();
    long long at, bt;
    cout << "a: " ;
    cin >> at;
    cout << "b: ";
    cin >> bt;
    cout << "\n";
    ReallyLongInt a = ReallyLongInt(at);
    ReallyLongInt b = ReallyLongInt(bt);
    numberTheory nt;
    ReallyLongInt ans = nt.extendedEuclid(a,b,x,y);
    cout << "gcd: " << ans.toString() << endl; //<< " " << ans.toStringBinary() << endl;
    cout << "x: " << x->toString() << endl ; // " " << x->toStringBinary() << endl;
    cout << "y: " << y->toString() << endl ; //" " << y->toStringBinary() << endl;
    //cout << (*x%*y).toString();




}
*/