//write include statements
#include <iostream>
#include "repetition.h"

//write using statements
using std::cout;
using std::cin;

int main() 
{
	int selection;// variable to hold user menu selection

	do // Loop until user chooses to exit
	{
		cout << "Homework 4 Menu\n 1 - Factorial\n 2 - Sum Odd Numbers\n 3 - Exit\n";
		cin >> selection;
		
		if (selection == 1) // Factorial option
		{
			int num;

			do // Input validation loop
			{
				cout << "Enter a number between 1 and 9: \n";
				cin >> num;
			} while (num < 1 || num > 9);

			int result = get_factorial(num);
			cout << "The factorial of " << num << " is " << result << "\n";
		}

		else if (selection == 2) // Sum odd numbers option
		{
			int num;

			do // Input validation loop
			{
				cout << "Enter a number between 1 and 99: \n";
				cin >> num;
			} while (num < 1 || num > 99);

			int result = sum_odd_numbers(num);
			cout << "The sum of odd numbers from 1 to " << num << " is " << result << "\n";
		}

		else if (selection == 3) // Exit option
		{
			cout << "Exiting... \n";

		}

		else // Invalid selection
		{
			cout << "Invalid choice. Please select 1, 2, or 3.\n";
		}

	} while (selection != 3); // Continue until user selects exit

	return 0;
}