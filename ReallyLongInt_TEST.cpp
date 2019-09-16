#define CATCH_CONFIG_MAIN //This will make our main for us :)
#include "catch.hpp"
#include "ReallyLongInt.hpp"

TEST_CASE("TESTING ReallyLongInt Class")
{
  ReallyLongInt *test_ReallyLongInt;

  SECTION("Default Constructor")
    {
     
      test_ReallyLongInt = new ReallyLongInt();

      INFO("Using default constructor") //Displayed if fails
      CAPTURE(test_ReallyLongInt->size); //Display this if fails
    
      //IF TEST FAIL -- STOP ALL TESTING
      REQUIRE(test_ReallyLongInt->size == 16); // Check if true
      REQUIRE_FALSE(test_ReallyLongInt->size != 16); //Check if false

      REQUIRE(test_ReallyLongInt->isNeg == false);
      REQUIRE_FALSE(test_ReallyLongInt->size != true); //Check if false

      REQUIRE(!(*(test_ReallyLongInt->digits)).empty());
      REQUIRE_FALSE((*(test_ReallyLongInt->digits)).empty()); //Check if false

      REQUIRE((*(test_ReallyLongInt->digits)).size() == 16);
      REQUIRE_FALSE((*(test_ReallyLongInt->digits)).size()!=16); //Check if false

      delete test_ReallyLongInt;
    }

  SECTION("Long Long Constructor")
    {
     
      test_ReallyLongInt = new ReallyLongInt(-1152921504606846976);

      INFO("Using default constructor") //Displayed if fails
      CAPTURE(test_ReallyLongInt->size); //Display this if fails
    
      //IF TEST FAIL -- STOP ALL TESTING
      REQUIRE(test_ReallyLongInt->size ==64); // Check if true
      REQUIRE_FALSE(test_ReallyLongInt->size != 64); //Check if false

      REQUIRE(test_ReallyLongInt->isNeg == true);
      REQUIRE_FALSE(test_ReallyLongInt->size != false); //Check if false

      REQUIRE(!(*(test_ReallyLongInt->digits)).empty());
      REQUIRE_FALSE((*(test_ReallyLongInt->digits)).empty()); //Check if false

      REQUIRE((*(test_ReallyLongInt->digits)).size() == 64);
      REQUIRE_FALSE((*(test_ReallyLongInt->digits)).size()!=64); //Check if false

      delete test_ReallyLongInt;
    }

    SECTION("Default Constructor")
    {
     
      test_ReallyLongInt = new ReallyLongInt("2305843009213693952");

      INFO("Using default constructor") //Displayed if fails
      CAPTURE(test_ReallyLongInt->size); //Display this if fails
    
      //IF TEST FAIL -- STOP ALL TESTING
      REQUIRE(test_ReallyLongInt->size == 64); // Check if true
      REQUIRE_FALSE(test_ReallyLongInt->size != 64); //Check if false

      REQUIRE(test_ReallyLongInt->isNeg == false);
      REQUIRE_FALSE(test_ReallyLongInt->size != false); //Check if false

      REQUIRE(!(*(test_ReallyLongInt->digits)).empty());
      REQUIRE_FALSE((*(test_ReallyLongInt->digits)).empty()); //Check if false

      REQUIRE((*(test_ReallyLongInt->digits)).size() == 64);
      REQUIRE_FALSE((*(test_ReallyLongInt->digits)).size()!=64); //Check if false

      delete test_ReallyLongInt;
    }

  SECTION("Max function")
    {
      test_vector = new Vector(10, 5.5);      
      REQUIRE(test_vector->max() == 5.5);
    }
}

TEST_CASE("Testing Nothing")
{
  SECTION("Nothing One")
    {
      REQUIRE(true);
    }


}

