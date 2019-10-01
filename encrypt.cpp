#include "ReallyLongInt.hpp"
#include "numberTheory.hpp"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]){
    ifstream kfile(argv[1]);
    string e_str;
    string n_str;
    fin>>e_str;
    fin>>n_str;
    ReallyLongInt e(stoll(e_str));
    ReallyLongInt n(stoll(n_str));
    kfile.close();

    ifstream text(argv[2]);
	  ofstream encrypt(argv[3]);

    char c;
	  while (text.get(c)){
      unsigned long long x =(unsigned long long)c;
      ReallyLongInt y = (x.exponent(e)) % n;
      encrypt << y.toString();
    }

    text.close();
    encrypt.close();

}