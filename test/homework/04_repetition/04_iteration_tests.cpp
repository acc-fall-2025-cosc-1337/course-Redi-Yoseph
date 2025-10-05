#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "repetition.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify get_factorial", "verification") {
	REQUIRE(get_factorial(0) == 1);
	REQUIRE(get_factorial(1) == 1);
	REQUIRE(get_factorial(5) == 120);
}

TEST_CASE("Verify sum_odd_numbers", "verification") {
	REQUIRE(sum_odd_numbers(1) == 1);
	REQUIRE(sum_odd_numbers(10) == 25);
	REQUIRE(sum_odd_numbers(20) == 100);
}