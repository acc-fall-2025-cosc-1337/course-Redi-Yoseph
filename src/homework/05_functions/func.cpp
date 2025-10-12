//add include statements
#include <iostream>
#include "func.h"
using std::string;


//add function code here
double get_gc_content(const string& dna)
{
    double gc_content = 0;

    for (std::size_t i = 0; i < dna.length(); i++)
    {
        if (dna[i] == 'C' || dna[i] == 'G')
            gc_content++;
    }
    return static_cast<double>(gc_content) / dna.length();
}

string reverse_string(string dna)
{
    string reverse = "";
    for (std::size_t i = dna.length(); i > 0; i--)
    {
        reverse += dna[i - 1];
    }
    return reverse;
}

string get_dna_complement(string dna)
{
    string complement = reverse_string(dna);

    for (std::size_t i = 0; i < complement.length(); i++)
    {
        if (complement[i] == 'A')
            complement[i] = 'T';
        else if (complement[i] == 'T')
            complement[i] = 'A';
        else if (complement[i] == 'G')
            complement[i] = 'C';
        else if (complement[i] == 'C')
            complement[i] = 'G';
    }
    
    return complement;
}