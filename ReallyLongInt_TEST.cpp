#define CATCH_CONFIG_MAIN //This will make our main for us :)
#include "catch.hpp"
#include "ReallyLongInt.hpp"
#include <string>

TEST_CASE("TESTING ReallyLongInt Class")
{
  ReallyLongInt *test_ReallyLongInt;

  SECTION("Default Constructor")
    {
     
      test_ReallyLongInt = new ReallyLongInt();

      INFO("Using default constructor") //Displayed if fails

      REQUIRE(test_ReallyLongInt->size == 16); // Check if true
      REQUIRE(test_ReallyLongInt->isNeg == false);
      REQUIRE(!(*(test_ReallyLongInt->digits)).empty());
      REQUIRE((*(test_ReallyLongInt->digits)).size() == 16);
      delete test_ReallyLongInt;
    }




  SECTION("Long Long Constructor")
    {
     
      test_ReallyLongInt = new ReallyLongInt(-4294967296);

      INFO("Using long long constructor") //Displayed if fails

      REQUIRE(test_ReallyLongInt->size ==64); // Check if true
      REQUIRE(test_ReallyLongInt->isNeg == true);
      REQUIRE(!(*(test_ReallyLongInt->digits)).empty());
      REQUIRE((*(test_ReallyLongInt->digits)).size() == 64);
      REQUIRE((*(test_ReallyLongInt->digits))[32] == 1);

      delete test_ReallyLongInt;
    }




   SECTION("String Constructor")
    {
     
      test_ReallyLongInt = new ReallyLongInt("-4294967296");

      INFO("Using string constructor") //Displayed if fails
      REQUIRE(test_ReallyLongInt->size ==64); // Check if true
      REQUIRE(test_ReallyLongInt->isNeg == true);
      REQUIRE(!(*(test_ReallyLongInt->digits)).empty());
      REQUIRE((*(test_ReallyLongInt->digits)).size() == 64);
      REQUIRE((*(test_ReallyLongInt->digits))[32] == 1);

      delete test_ReallyLongInt;
    }




     SECTION("Copy Constructor")
    {
     
      ReallyLongInt other("-4294967296");
      test_ReallyLongInt = new ReallyLongInt(other);

      INFO("Using copy constructor") //Displayed if fails

      REQUIRE(test_ReallyLongInt->size ==64); // Check if true
      REQUIRE(test_ReallyLongInt->isNeg == true);
      REQUIRE(!(*(test_ReallyLongInt->digits)).empty());
      REQUIRE((*(test_ReallyLongInt->digits)).size() == 64);
      REQUIRE((*(test_ReallyLongInt->digits))[32] == 1);

      delete test_ReallyLongInt;
      delete &other;
    }


  SECTION("Equal test1")
    {
      test_ReallyLongInt = new ReallyLongInt();
      ReallyLongInt testing; 

      INFO("Testing equal") //Displayed if fails
      REQUIRE(test_ReallyLongInt->equal(testing));
    }

    SECTION("Equal test2")
    {
      test_ReallyLongInt = new ReallyLongInt();
      ReallyLongInt testing(2); 

      INFO("Testing unequal") //Displayed if fails
      REQUIRE(!test_ReallyLongInt->equal(testing));
    }

      SECTION("Greater test1")
    {
      test_ReallyLongInt = new ReallyLongInt(3);
      ReallyLongInt testing(2); 

      INFO("Testing greater") //Displayed if fails
      REQUIRE(test_ReallyLongInt->greater(testing));
    }

    SECTION("Greater test2")
    {
      test_ReallyLongInt = new ReallyLongInt(2);
      ReallyLongInt testing(2); 

      INFO("Testing equal(greater)") //Displayed if fails
      REQUIRE(!test_ReallyLongInt->greater(testing));
    }

    SECTION("Greater test3")
    {
      test_ReallyLongInt = new ReallyLongInt(2);
      ReallyLongInt testing(3); 

      INFO("Testing smaller(greater)") //Displayed if fails
      REQUIRE(!test_ReallyLongInt->greater(testing));
    }

    SECTION("toString test")
    {
      test_ReallyLongInt = new ReallyLongInt(2);

      INFO("Testing toString") //Displayed if fails
      REQUIRE((test_ReallyLongInt->toString()).compare("2"));
    }

     SECTION("toBinary test")
    {
      test_ReallyLongInt = new ReallyLongInt(2);

      INFO("Testing toBinaryString") //Displayed if fails
      REQUIRE((test_ReallyLongInt->toStringBinary()).compare("0000000000000010"));
    }








}


