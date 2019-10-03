#include "ReallyLongInt.hpp"
#include "numberTheory.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>


using namespace std; 


int main(int argc, char *argv[]){
    ReallyLongInt a(stoll(argv[1]));
    ReallyLongInt b(stoll(argv[2]));

    if(!a.isPrime() || !b.isPrime()){
        cout << "at least one of the inputs is not a prime number" << endl;
        return 1;
    }
    ofstream pkfile, skfile;
    pkfile.open(argv[3]);
    skfile.open(argv[4]);

    ReallyLongInt n, t;
    n = a * b;
    t = (a-1) * (b-1);

    ReallyLongInt* x;
    ReallyLongInt* y;
    ReallyLongInt gcd;
    ReallyLongInt d;
    long long e = 2;
    for(; e < t; e ++){
        numberTheory nt;
        gcd = nt.extendedEulid(e, t, x, y);
        if(gcd == 1)
            break;
    }
    d = *x;
    if(d < 0)
        d = d + t;

    pkfile << e << " " << n.toString() << endl;
    skfile << d.toString() << " " << n.toString() << endl;

    pkfile.close();
    skfile.close();
}