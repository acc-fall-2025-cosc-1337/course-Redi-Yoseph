//write include statements
#include<iostream>
#include<iomanip>
#include<cmath>
#include "hwexpressions.h"


//write namespace using statement for cout
using namespace std; 
using std::cin; using std::cout; using std::setw; using std::setprecision;
using std::right; using std::left;
int main()
{
	double meal_amount;
    double tip_rate;

    // User input
    cout << "Enter meal amount: ";
    cin >> meal_amount;

    cout << "Enter tip rate (as decimal, e.g. 0.15 for 15%): ";
    cin >> tip_rate;

    // Calculations
    double sales_tax = get_sales_tax_amount(meal_amount);
    double tip_amount = get_tip_amount(meal_amount, tip_rate);
    double total = meal_amount + sales_tax + tip_amount;

    // Display receipt
    cout << fixed << setprecision(2);
    cout << "\n--- Receipt ---\n";
    cout << "Meal Amount:   $" << meal_amount << endl;
    cout << "Sales Tax:     $" << sales_tax << endl;
    cout << "Tip Amount:    $" << tip_amount << endl;
    cout << "Total:         $" << total << endl;

	return 0;
}
