#include "ReallyLongInt.hpp"
#include "numberTheory.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]){

    if (argc != 4) {
        cout << "Wrong Number of Command Line Arguments Passed";
        return 0;
    }

    ifstream kfile;
    kfile.open(argv[1]);
    if (!kfile.good()) throw "I/O error";
    string e_str;
    string n_str;
    kfile>>e_str;
    kfile>>n_str;
    ReallyLongInt e(stoll(e_str));
    ReallyLongInt n(stoll(n_str));
    cout << "e: " << e.toString() << " n:" << n.toString() << endl;
    kfile.close();

    ifstream text(argv[2]);
	ofstream encrypt(argv[3]);

    char c;
	while (text.get(c)){
      unsigned long long a =(unsigned long long)c;
      cout << "a:"  << a  << endl;
      ReallyLongInt x(a);
      ReallyLongInt y = (x.exponent(e)) % n;
      cout << "y:" << y.toString() << endl;
      cout << "ascii: " << stoi(y.toString()) << endl;
      //encrypt << '0' + stoi(y.toString());
      //cout << (char)stoi(y.toString());
      //encrypt << (char)stoi(y.toString());
      encrypt << " " << y.toString() ;
    }

    text.close();
    encrypt.close();

}