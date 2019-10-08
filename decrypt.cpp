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
    cout << "d:" << d.toString() << endl;
    cout << "n:" << n.toString() << endl;

    kfile.close();

    ifstream enctext(argv[2]);
	ofstream decrypt(argv[3]);

    char c;
	while (enctext.get(c)){
      unsigned long long ytemp =(unsigned long long)c;
      cout << "c:"  << c << endl;
      cout << "ytemp" << ytemp << endl;
      ReallyLongInt y(ytemp);
      ReallyLongInt x = (y.exponent(d)) % n;
      cout << "exp: " << y.exponent(d).toString();
      cout << "x:" << x.toString() << endl;
      cout << "ascii: " << stoi(x.toString()) << endl;
      decrypt << (char)stoi(x.toString());
      //decrypt << '0' + stoi(x.toString());
    }

    enctext.close();
    decrypt.close();

}