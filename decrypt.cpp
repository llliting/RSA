#include "ReallyLongInt.hpp"
#include "numberTheory.hpp"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]){

    if (argc != 4) {
        cout << "Wrong Number of Command Line Arguments Passed";
        return 0;
    }

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

	while (!enctext.eof()){
      string ytemp;
      enctext >> ytemp;
      ReallyLongInt y(ytemp);
      ReallyLongInt x = (y.exponent(d)) % n;
      decrypt << (char)stoi(x.toString());
    }

    enctext.close();
    decrypt.close();

}