#include "ReallyLongInt.hpp"
#include "numberTheory.hpp"
#include "numberTheory.cpp"

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>


using namespace std; 


int main(int argc, char *argv[]){

    ReallyLongInt a(stoll(argv[1]));
    ReallyLongInt b(stoll(argv[2]));

    if (argc != 5) {
        cout << "Wrong Number of Command Line Arguments Passed";
        return 0;
    }

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

    ReallyLongInt* x = new ReallyLongInt();
    ReallyLongInt* y = new ReallyLongInt();
    ReallyLongInt gcd;
    ReallyLongInt d;
    ReallyLongInt e(2);
    numberTheory nt;
    for(; e < t; e = e+1){
        gcd = nt.extendedEuclid(e, t, x, y);
        if(gcd == 1)
            break;       
    }
    d = *x;
    while(d < 0)////////?? while or if
        d = d + t;

    pkfile << e.toString() << " " << n.toString() << endl;
    skfile << d.toString() << " " << n.toString() << endl;

    pkfile.close();
    skfile.close();
    delete x;
    delete y;
    return 0;
}