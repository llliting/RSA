#include "ReallyLongInt.hpp"
#include "numberTheory.hpp"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]){
    ifstream kfile(argv[1]);
    string d_str;
    string n_str;
    fin>>d_str;
    fin>>n_str;
    ReallyLongInt d(stoll(d_str));
    ReallyLongInt n(stoll(n_str));
    kfile.close();

    ifstream enctext(argv[2]);
	ofstream decrypt(argv[3]);

    char c;
	while (text.get(c)){
      unsigned long long y =(unsigned long long)c;

      ReallyLongInt x = (y.exponent(d)) % n;
      encrypt << (char)y;
    }

    enctext.close();
    decrypt.close();

}