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
      REQUIRE((test_ReallyLongInt->toString()) == "0");
      delete test_ReallyLongInt;

      test_ReallyLongInt = new ReallyLongInt(-4294967296);
      INFO("Using long long constructor") //Displayed if fails
      REQUIRE((test_ReallyLongInt->toString()) == "-4294967296");
      delete test_ReallyLongInt;

      test_ReallyLongInt = new ReallyLongInt();
      INFO("Using long long constructor") //Displayed if fails
      REQUIRE((test_ReallyLongInt->toStringBinary()) == "0");
      delete test_ReallyLongInt;

      ReallyLongInt other("-4294967296");
      ReallyLongInt test(other);
      INFO("Using copy constructor") //Displayed if fails
      REQUIRE(test.toString() == "-4294967296");
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
      REQUIRE(((a+b).toString()) == "4");
      
      a = ReallyLongInt(1); //1 + 1
      b = ReallyLongInt(3);
      REQUIRE(((a+b).toString()) == "4");

      a = ReallyLongInt(7);
      b = ReallyLongInt(7);
      REQUIRE(((a+b).toString()) == "14");

      INFO("pos - pos fail") //Displayed if fails
      REQUIRE(((a-b).toString()) == "0");

      a = ReallyLongInt(8);
      b = ReallyLongInt(7);
      REQUIRE(((a-b).toString()) == "1");

      a = ReallyLongInt(4);
      b = ReallyLongInt(8);
      REQUIRE(((a-b).toString()) == "-4");

      INFO("pos neg fail")
      a = ReallyLongInt(-4);//neg and pos
      REQUIRE(((a-b).toString()) == "-12");
      REQUIRE(((a+b).toString()) == "4");
      b = ReallyLongInt(-2);//neg and neg
      REQUIRE(((a-b).toString()) == "-2");
      REQUIRE(((a+b).toString()) == "-6");
      a = ReallyLongInt(4);//pos and neg
      REQUIRE(((a-b).toString()) == "6");
      REQUIRE(((a+b).toString()) == "2");
    }

  SECTION("mult test")
    {
      ReallyLongInt a(7);
      ReallyLongInt b(7);
      INFO("multiplication fail")
      REQUIRE(((a*b).toString()) == "49");

      a = ReallyLongInt(2);
      REQUIRE(((a*b).toString()) == "14");

      b = ReallyLongInt(2);
      a = ReallyLongInt(15);
      REQUIRE(((a*b).toString()) == "30");

      a = -a;
      REQUIRE(((a*b).toString()) == "-30");
    }

  SECTION("div test")
    {
      ReallyLongInt a(7);
      ReallyLongInt b(7);
      INFO("division test fail")
      REQUIRE(((a/b).toString()) == "1");
      REQUIRE(((a%b).toString()) == "0");

      a = ReallyLongInt(15);
      REQUIRE(((a/b).toString()) == "2");
      REQUIRE(((a%b).toString()) == "1");

      a = -a;
      REQUIRE(((a/b).toString()) == "-2");
      REQUIRE(((a%b).toString()) == "1");
    }
}


