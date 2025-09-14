//write include statements

#include <iostream>
#include "data_types.h"

//write namespace using statement for cout
using std::cout;
using std::endl;

int multiply_numbers(int num1, int num2) {
    return num1 * num2;
}

int main() {
    cout << "7 x 7 = " << multiply_numbers(7, 7) << endl;
    cout << "5 x 5 = " << multiply_numbers(5, 5) << endl;
    return 0;
}


