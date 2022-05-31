//==============================================
// Name           : MD FAIAZ
// Email          : mfaiaz@myseneca.ca
// Student ID     : 164899213
// Section        : NAA
// Date           : 30/05/2022
//==============================================
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#include <iostream>
#include <cstring>
#include "Population.h"
#include "File.h"
#include "Utils.h"

using namespace std;
namespace sdds
{
    // Global variables
    int totalPost;
    int totalPopu;
    PostalCode* postcode;

    void sort()
    {
        int i, j;
        PostalCode temp;
        for (i = totalPost - 1; i > 0; i--)
        {
            for (j = 0; j < i; j++)
            {
                if (postcode[j].population > postcode[j + 1].population)
                {
                    temp = postcode[j];
                    postcode[j] = postcode[j + 1];
                    postcode[j + 1] = temp;
                }
            }
        }
    }

    bool load(PostalCode& post)
    {
        char code[4];
        bool result = false;

        if (read(code) && read(post.population))
        {
            post.postal_code = new char[strLen(code) + 1];
            strCpy(post.postal_code, code);
            result = true;
        }
        return result;
    }

    bool load(const char filename[])
    {
        int i = 0;
        bool result = false;

        if (openFile(filename))
        {
            totalPost = noOfRecords();

            postcode = new PostalCode[totalPost];

            for (int j = 0; j < totalPost; j++)
            {
                i += load(postcode[j]);
            }

            if (i != totalPost)
            {
                cout << "Error: incorrect number of records read; the data is possibly corrupted!" << endl;
            }
            else
            {
                result = true;
            }

            closeFile();
        }
        else
        {
            cout << "Could not open data file: " << filename << endl;
        }

        return result;
    }

    void display(const PostalCode& code)
    {
        cout << code.postal_code << ":  " << code.population << endl;
    }

    void display()
    {
        cout << "Postal Code: population" << endl;
        cout << "-------------------------" << endl;

        sort();

        for (int i = 0; i < totalPost; i++)
        {
            cout << i + 1 << "- ";
            display(postcode[i]);
            totalPopu += postcode[i].population;
        }

        cout << "-------------------------" << endl;
        cout << "Population of Canada: " << totalPopu << endl;
    }

    void deallocateMemory()
    {
        for (int i = 0; i < totalPost; i++)
        {
            delete[] postcode[i].postal_code;
        }
        delete[] postcode;
    }
}