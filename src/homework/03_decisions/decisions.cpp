//write include statement for decisions header
#include <iostream>
#include <string>
#include "decisions.h"

//Write code for function(s) code here
std::string get_letter_grade_using_if(int g)
{
    if (g < 0 || g > 100) return "Invalid";

    if (g >= 90) return "A";
    else if (g >= 80) return "B";
    else if (g >= 70) return "C";
    else if (g >= 60) return "D";
    else return "F";
}

std::string get_letter_grade_using_switch(int g)
{
    if (g < 0 || g > 100) return "Invalid";

    // Use multiples of ten to keep the switch compact
    switch (g / 10)
    {
        case 10: // 100
        case 9:  return "A"; // 90–99
        case 8:  return "B"; // 80–89
        case 7:  return "C"; // 70–79
        case 6:  return "D"; // 60–69
        default: return "F"; // 0–59
    }
}
