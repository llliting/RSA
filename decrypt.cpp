#include "ReallyLongInt.hpp"
#include "numberTheory.hpp"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]){
    ifstream kfile(argv[1]);
    string d_str;
    string n_str;
    kfile>>d_str;
    kfile>>n_str;
    ReallyLongInt d(stoll(d_str));
    ReallyLongInt n(stoll(n_str));
    kfile.close();

    ifstream enctext(argv[2]);
	ofstream decrypt(argv[3]);

    char c;
	while (enctext.get(c)){
      unsigned long long ytemp =(unsigned long long)c;
      ReallyLongInt y(ytemp);
      ReallyLongInt x = (y.exponent(d)) % n;
      decrypt << (char)stoi(x.toString());
    }

    enctext.close();
    decrypt.close();

}