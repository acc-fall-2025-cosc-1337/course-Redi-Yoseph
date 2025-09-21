#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "hwexpressions.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Verify sum_numbers function") 
{
	REQUIRE(add_numbers(5, 5) == 10);
	REQUIRE(add_numbers(10, 10) == 20);
}

using namespace std;

int main()
{
    // Test get_sales_tax_amount
    double tax = get_sales_tax_amount(20.0);  // 20 * 0.0675 = 1.35
    assert(abs(tax - 1.35) < 0.001);

    // Test get_tip_amount
    double tip = get_tip_amount(20.0, 0.15);  // 20 * 0.15 = 3.0
    assert(abs(tip - 3.0) < 0.001);

    cout << "All tests passed!" << endl;
    return 0;
}