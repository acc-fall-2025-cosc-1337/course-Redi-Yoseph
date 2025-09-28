//write include statements
#include <iostream>
#include <string>
#include <decisions.h>

int main() 
{
    int choice;
    int grade;
    
	std::cout << "MAIN MENU\n\n";
    std::cout << "1-Letter grade using if\n";
    std::cout << "2-Letter grade using switch\n";
    std::cout << "3-Exit\n\n";

    int choice{};
    std::cout << "Enter option (1-3): ";
    if (!(std::cin >> choice)) {
        std::cout << "Invalid input.\n";
        return 0; // one-run program ends
    }

    if (choice == 1 || choice == 2) {
        int grade{};
        std::cout << "Enter numerical grade (0-100): ";
        if (!(std::cin >> grade)) {
            std::cout << "Invalid input.\n";
            return 0;
        }

        if (grade < 0 || grade > 100) {
            std::cout << "Number is out of range.\n";
            return 0;
        }

        std::string letter =
            (choice == 1)
            ? get_letter_grade_using_if(grade)
            : get_letter_grade_using_switch(grade);

        std::cout << "Letter Grade: " << letter << "\n";
    }
    else if (choice == 3) {
        // Do nothing; exit
    }
    else {
        std::cout << "Invalid option.\n";
    }

	return 0;
}