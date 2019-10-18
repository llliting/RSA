#define CATCH_CONFIG_MAIN //This will make our main for us :)
#include "catch.hpp"
#include "numberTheory.cpp"
#include "ReallyLongInt.hpp"
#include <iostream>
#include <string>


TEST_CASE("TESTING numberTheory Class")
{
    ReallyLongInt a(3);
    ReallyLongInt b(13);
    ReallyLongInt x,y;
    numberTheory nt;
    ReallyLongInt ans = nt.extendedEuclid(a,b,x,y);
    ReallyLongInt check(1);
    REQUIRE(ans.equal(check));
    REQUIRE(y.equal(check));
    check = ReallyLongInt(-4);
    REQUIRE(x.equal(check));
}