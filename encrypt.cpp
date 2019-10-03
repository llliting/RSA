#include "ReallyLongInt.hpp"
#include "numberTheory.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]){
    ifstream kfile;
    kfile.open(argv[1]);
    if (!kfile.good()) throw "I/O error";
    string e_str;
    string n_str;
    kfile>>e_str;
    kfile>>n_str;
    ReallyLongInt e(stoll(e_str));
    ReallyLongInt n(stoll(n_str));
    kfile.close();

    ifstream text(argv[2]);
	  ofstream encrypt(argv[3]);

    char c;
	  while (text.get(c)){
      unsigned long long a =(unsigned long long)c;
      ReallyLongInt x(a);
      ReallyLongInt y = (x.exponent(e)) % n;
      encrypt << (char)stoi(y.toString());
    }

    text.close();
    encrypt.close();

}