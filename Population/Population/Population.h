//==============================================
// Name           : MD FAIAZ
// Email          : mfaiaz@myseneca.ca
// Student ID     : 164899213
// Section        : NAA
// Date           : 30/05/2022
//==============================================
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
namespace sdds {

    struct PostalCode
    {
        char* postal_code;
        int population;
    };


    void sort();
    bool load(PostalCode& post);
    bool load(const char filename[]);
    void display(const PostalCode& postal_code);
    void display();
    void deallocateMemory();

}
#endif // SDDS_POPULATION_H_#pragma once
