#include <iostream>
#include "func.h"

using namespace std;

int main() 
{
    int option = 0;

    do {
        cout << "\n1- Get GC Content.\n";
        cout << "2- Get DNA Complement.\n";
        cout << "3- Exit.\n";
        cout << "Choose an option: ";
        cin >> option;

        if (option == 1)
        {
            string gc;
            cout << "Input DNA string to calculate GC content: ";
            cin >> gc;

            double result = get_gc_content(gc);
            cout << "GC Content: " << result << endl;
        }
        else if (option == 2)
        {
            string complement;
            cout << "Please enter DNA string to get complement: ";
            cin >> complement;

            string result = get_dna_complement(complement);
            cout << "DNA Complement: " << result << endl;
        }
        else if (option != 3)
        {
            cout << "Invalid option. Try again.\n";
        }

    } while (option != 3);

    cout << "Exiting program.\n";
    return 0;
}
