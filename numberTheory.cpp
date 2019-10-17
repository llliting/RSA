#include "numberTheory.hpp"
#include "ReallyLongInt.hpp"



using namespace std;




ReallyLongInt numberTheory::extendedEuclid(const ReallyLongInt& a, const ReallyLongInt& b, 
                            ReallyLongInt* output_x, ReallyLongInt* output_y){
    if(b == 0){
        *output_x = ReallyLongInt(1);
        *output_y = ReallyLongInt(0);
        return a;
    }
    else{
       ReallyLongInt d = extendedEuclid(b, a%b, output_x, output_y);
       ReallyLongInt temp = *output_x;
       *output_x = *output_y;
       *output_y = temp - ((*output_y) * (a / b));
       return d;
    }
}

int main(){
    long long m, n;
    cout << "x: " ;
    cin >> m;
    cout << "y: ";
    cin >> n; 
    ReallyLongInt a(m);
    ReallyLongInt b(n);
    ReallyLongInt x,y;
    numberTheory nt;

    ReallyLongInt ans = nt.extendedEuclid(a, b, &x, &y);
    cout << "x: " << x.toString() << endl;
    cout << "y: " << y.toString() << endl;
    cout << "ans: " << ans.toString() << endl;


}