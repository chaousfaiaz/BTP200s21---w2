//==============================================
// Name           : MD FAIAZ
// Email          : mfaiaz@myseneca.ca
// Student ID     : 164899213
// Section        : NAA
// Date           : 30/05/2022
//==============================================
#include "Population.h"
using namespace sdds;
int main()
{
    if (load("PCpopulationsComplete.csv"))
    {
        display();
    }
    deallocateMemory();
    return 0;
}