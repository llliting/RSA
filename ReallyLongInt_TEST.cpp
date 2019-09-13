#define CATCH_CONFIG_MAIN //This will make our main for us :)
#include "catch.hpp"

//What are we testing today?
#include "ReallyLongInt.hpp"


TEST_CASE("TESTING ReallyLongInt Class")
{
  ReallyLongInt *test_RLI;

  SECTION("Default Constructor")
    {
     
      test_RLI = new ReallyLongInt();

      //Information to be printed if error (optional stuff)
      INFO("Using default constructor") //Displayed if fails
      CAPTURE(test_RLI->getSize()); //Display this if fails
     
      
      //IF TEST FAIL -- STOP ALL TESTING
      REQUIRE(test_RLI->getSize() == 16); // Check if true
      REQUIRE_FALSE(test_RLI->getSize() != 16); //Check if false

      
      //IF TEST FAIL -- CONTINUE TESTING
      //CHECK(test_vector->size() == 1);

      delete test_RLI;
    }



   SECTION("Long Long Constructor")
    {
     
      test_RLI = new ReallyLongInt(100000);

      //Information to be printed if error (optional stuff)
      INFO("Using long long num constructor") //Displayed if fails
      CAPTURE(test_RLI->getSize()); //Display this if fails
     
      
      //IF TEST FAIL -- STOP ALL TESTING
      REQUIRE(test_RLI->getSize() == 32); // Check if true
      REQUIRE_FALSE(test_RLI->getSize() != 32); //Check if false

      
      //IF TEST FAIL -- CONTINUE TESTING
      //CHECK(test_vector->size() == 1);

      delete test_RLI;
    }

/*

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

*/


}
