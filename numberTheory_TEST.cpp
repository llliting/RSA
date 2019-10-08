#define CATCH_CONFIG_MAIN //This will make our main for us :)
#include "catch.hpp"
#include "numberTheory.hpp"
#include "ReallyLongInt.hpp"
#include <iostream>
#include <string>


TEST_CASE("TESTING numberTheory Class")
{
    ReallyLongInt a(3);
    ReallyLongInt b(13);
    ReallyLongInt* x = new ReallyLongInt();
    ReallyLongInt* y = new ReallyLongInt();
    numberTheory nt;
    ReallyLongInt ans = nt.extendedEuclid(a,b,x,y);


    REQUIRE(ans.toString() == "1");
    REQUIRE(x->toString() == "-4");
    REQUIRE(y->toString() == "1");
}