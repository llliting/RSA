#include "numberTheory.hpp"
#include "ReallyLongInt.hpp"



using namespace std;


ReallyLongInt extendedEulid(const ReallyLongInt& a, const ReallyLongInt& b, 
                            ReallyLongInt* output_x, ReallyLongInt* output_y){
    if(b == 0){
        output_x = new ReallyLongInt(1);
        output_y = new ReallyLongInt(0);
        return a;
    }
    else{
       ReallyLongInt d = extendedEulid(b, a%b, output_x, output_y);
       ReallyLongInt temp = *output_x;
       output_x = output_y;
       *output_y = *output_x - ((*output_y) * (a / b));
       return d;
    }
}
/*
int main(){
    long long a;
    long long b;
    printf("a: ");
    cin >> a;
    printf("b : ");
    cin >> b;
    ReallyLongInt x(a);
    ReallyLongInt y(b);
    ReallyLongInt* p = new ReallyLongInt();
    ReallyLongInt* q = new ReallyLongInt();
    ReallyLongInt z = extendedEulid(x, y, p, q);

    cout << "ans: " << z.toString() << endl;
    cout << "p: " << p->toString() << endl;
    cout << "q: " << q->toString() << endl;
}
*/