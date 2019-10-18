#define CATCH_CONFIG_MAIN //This will make our main for us :)
#include "catch.hpp"
#include "ReallyLongInt.hpp"
#include <string>


TEST_CASE("TESTING ReallyLongInt Class")
{
    ReallyLongInt *test_ReallyLongInt;
    
    SECTION("Constructor")
    {
        
        test_ReallyLongInt = new ReallyLongInt();
        INFO("Using default constructor") //Displayed if fails
        ReallyLongInt ans(0);
        REQUIRE(test_ReallyLongInt->equal(ans));
        delete test_ReallyLongInt;
        
        test_ReallyLongInt = new ReallyLongInt(-4294967296);
        INFO("Using long long constructor") //Displayed if fails
        ans = ReallyLongInt(-4294967296);
        REQUIRE(test_ReallyLongInt->equal(ans));
        delete test_ReallyLongInt;
        
        test_ReallyLongInt = new ReallyLongInt();
        INFO("Using long long constructor") //Displayed if fails
        ans = ReallyLongInt(0);
        REQUIRE(test_ReallyLongInt->equal(ans));
        delete test_ReallyLongInt;
        
        ReallyLongInt other("-4294967296");
        ReallyLongInt test(other);
        INFO("Using copy constructor") //Displayed if fails
        ans = ReallyLongInt(-4294967296);
        REQUIRE(test.equal(ans));
    }
    
    SECTION("Equal test")
    {
        test_ReallyLongInt = new ReallyLongInt();
        ReallyLongInt testing;
        INFO("Testing equal") //Displayed if fails
        REQUIRE(test_ReallyLongInt->equal(testing));
        
        testing = ReallyLongInt(2);
        INFO("Testing unequal") //Displayed if fails
        REQUIRE(!test_ReallyLongInt->equal(testing));
        
        testing = ReallyLongInt(-2);
        INFO("Testing sign difference") //Displayed if fails
        REQUIRE(!test_ReallyLongInt->equal(testing));
        delete test_ReallyLongInt;
        
        test_ReallyLongInt = new ReallyLongInt(1000000);
        testing = ReallyLongInt(2);
        INFO("Testing sign difference") //Displayed if fails
        REQUIRE(!test_ReallyLongInt->equal(testing));
        delete test_ReallyLongInt;
    }
    
    SECTION("Greater test")
    {
        test_ReallyLongInt = new ReallyLongInt(3);
        ReallyLongInt testing(2);
        INFO("Testing greater") //Displayed if fails
        REQUIRE(test_ReallyLongInt->greater(testing));
        delete test_ReallyLongInt;
        
        test_ReallyLongInt = new ReallyLongInt(2);
        testing = ReallyLongInt(2);
        INFO("Testing equal(greater)") //Displayed if fails
        REQUIRE(!test_ReallyLongInt->greater(testing));
        delete test_ReallyLongInt;
        
        test_ReallyLongInt = new ReallyLongInt(2);
        testing = ReallyLongInt(3);
        INFO("Testing smaller(greater)") //Displayed if fails
        REQUIRE(!test_ReallyLongInt->greater(testing));
        delete test_ReallyLongInt;
        
        test_ReallyLongInt = new ReallyLongInt(-2);
        testing = ReallyLongInt(3);
        INFO("Testing neg < pos") //Displayed if fails
        REQUIRE(!test_ReallyLongInt->greater(testing));
        delete test_ReallyLongInt;
        
        test_ReallyLongInt = new ReallyLongInt(2);
        testing = ReallyLongInt(-3);
        INFO("Testing pos > neg") //Displayed if fails
        REQUIRE(test_ReallyLongInt->greater(testing));
        delete test_ReallyLongInt;
        
        test_ReallyLongInt = new ReallyLongInt(8589934592);
        testing = ReallyLongInt(1073741824);
        INFO("Testing size larger") //Displayed if fails
        REQUIRE(test_ReallyLongInt->greater(testing));
        delete test_ReallyLongInt;
        
        test_ReallyLongInt = new ReallyLongInt(1073741824);
        testing = ReallyLongInt(8589934592);
        INFO("Testing size smaller") //Displayed if fails
        REQUIRE(!test_ReallyLongInt->greater(testing));
        delete test_ReallyLongInt;
        
        test_ReallyLongInt = new ReallyLongInt(20);
        testing = ReallyLongInt(4294967296);
        INFO("Testing bits smaller") //Displayed if fails
        REQUIRE(!test_ReallyLongInt->greater(testing));
        delete test_ReallyLongInt;
        
        test_ReallyLongInt = new ReallyLongInt(4294967296);
        testing = ReallyLongInt(30);
        INFO("Testing bits larger") //Displayed if fails
        REQUIRE(test_ReallyLongInt->greater(testing));
        delete test_ReallyLongInt;
    }
    
    
    
    
    
    SECTION("toString test")
    {
        test_ReallyLongInt = new ReallyLongInt(3);
        CAPTURE((test_ReallyLongInt->toString()))
        INFO("Testing toString") //Displayed if fails
        REQUIRE((test_ReallyLongInt->toString()) == "3");
        delete test_ReallyLongInt;
        
        test_ReallyLongInt = new ReallyLongInt(2);
        INFO("Testing toBinaryString") //Displayed if fails
        REQUIRE((test_ReallyLongInt->toStringBinary()) == "10");
        delete test_ReallyLongInt;
    }
    
    
    SECTION("Add and Sub test")
    {
        INFO("pos + pos fail") //Displayed if fails
        ReallyLongInt a(3);
        ReallyLongInt b(1);
        ReallyLongInt c;
        ReallyLongInt ans(4);
        REQUIRE((a+b).equal(ans));
        
        a = ReallyLongInt(1); //1 + 1
        b = ReallyLongInt(3);
        REQUIRE((a+b).equal(ans));
        
        a = ReallyLongInt(7);
        b = ReallyLongInt(7);
        ans = ReallyLongInt(14);
        REQUIRE((a+b).equal(ans));
        
        INFO("pos - pos fail") //Displayed if fails
        ans = ReallyLongInt(0);
        REQUIRE((a-b).equal(ans));
        
        a = ReallyLongInt(8);
        b = ReallyLongInt(7);
        ans = ReallyLongInt(1);
        REQUIRE((a-b).equal(ans));
        
        a = ReallyLongInt(4);
        b = ReallyLongInt(8);
        ans = ReallyLongInt(-4);
        REQUIRE((a-b).equal(ans));
        
        INFO("pos neg fail")
        a = ReallyLongInt(-4);//neg and pos
        ans = ReallyLongInt(-12);
        REQUIRE((a-b).equal(ans));
        ans = ReallyLongInt(4);
        REQUIRE((a+b).equal(ans));
        
        b = ReallyLongInt(-2);//neg and neg
        ans = ReallyLongInt(-2);
        REQUIRE((a-b).equal(ans));
        ans = ReallyLongInt(-6);
        REQUIRE((a+b).equal(ans));
        
        a = ReallyLongInt(4);//pos and neg
        ans = ReallyLongInt(6);
        REQUIRE((a-b).equal(ans));
        ans = ReallyLongInt(2);
        REQUIRE((a+b).equal(ans));
    }
    
    SECTION("mult test")
    {
        ReallyLongInt a(7);
        ReallyLongInt b(7);
        INFO("multiplication fail")
        ReallyLongInt ans(49);
        REQUIRE((a*b).equal(ans));
        
        a = ReallyLongInt(2);
        ans = ReallyLongInt(14);
        REQUIRE((a*b).equal(ans));
        
        b = ReallyLongInt(2);
        a = ReallyLongInt(15);
        ans = ReallyLongInt(30);
        REQUIRE((a*b).equal(ans));
        
        a = -a;
        ans = ReallyLongInt(-30);
        REQUIRE((a*b).equal(ans));
    }
    
    SECTION("div test")
    {
        ReallyLongInt a(7);
        ReallyLongInt b(7);
        ReallyLongInt ans(1);
        INFO("division test fail")
        REQUIRE((a/b).equal(ans));
        ans = ReallyLongInt(0);
        REQUIRE((a%b).equal(ans));
        
        a = ReallyLongInt(15);
        ans = ReallyLongInt(2);
        REQUIRE((a/b).equal(ans));
        ans = ReallyLongInt(1);
        REQUIRE((a%b).equal(ans));
        
        
        a = -a;
        ans = ReallyLongInt(-2);
        REQUIRE((a/b).equal(ans));
        ans = ReallyLongInt(6);
        REQUIRE((a%b).equal(ans));
    }
    
    SECTION("exponent test")
    {
        ReallyLongInt a(2);
        ReallyLongInt b(3);
        INFO("exponent test fail")
        ReallyLongInt ans = ReallyLongInt(8);
        REQUIRE((a.exponent(b)).equal(ans));
        ans = ReallyLongInt(9);
        REQUIRE((b.exponent(a)).equal(ans));
    }
    
    SECTION("prime test")
    {
        ReallyLongInt a(2);
        ReallyLongInt b(127);
        REQUIRE(b>=a);
        ReallyLongInt c(8);
        ReallyLongInt d(15);
        INFO("prime test fail")
        REQUIRE(a.isPrime());
        REQUIRE(b.isPrime());
        REQUIRE(!c.isPrime());
        REQUIRE(!d.isPrime());
        
    }
}


