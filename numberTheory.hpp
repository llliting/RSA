#ifndef NUMBERTHEORY_H
#define NUMBERTHEORY_H

#include "ReallyLongInt.cpp"
using namespace std;

std::tuple <ReallyLongInt, ReallyLongInt, ReallyLongInt> extendedEulid(const ReallyLongInt& a, const ReallyLongInt& b);

#endif