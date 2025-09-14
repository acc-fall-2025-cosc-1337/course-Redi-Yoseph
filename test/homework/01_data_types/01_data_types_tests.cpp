#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "data_types.h"
#include <catch2/catch_test_macros.hpp>
TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("multiply_numbers works", "[multiply_numbers]") 
{
    REQUIRE(multiply_numbers(7, 7) == 49);
    REQUIRE(multiply_numbers(5, 5) == 25);
}
 

