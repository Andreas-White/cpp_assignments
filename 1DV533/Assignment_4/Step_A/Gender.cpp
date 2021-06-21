//-----------------------------------------------------------------------
// File: Gender.cpp
// Summary: Takes as input the personal number of an individual and prints
// out the correct gender
// Version: 1.1
// Owner: Andreas Manos
//-----------------------------------------------------------------------
// Log: 2020-12-14 Created the file, Andreas.
//-----------------------------------------------------------------------

#include <iostream>
#include <cctype>

using namespace std;

// Prototype
bool isValid(char array[],int size);

// Initialise constants
const int MAX = 100;
const int SIZE = 10;

int main ()
{
    // initialise variables
    char choice;
    char perNum[MAX] = {'0'};
    bool check;

    do
    {
        system("CLS");
        // Ask the user for input
        cout << "Please enter a Social Security Number: ";
        cin.getline(perNum,MAX);

        check = isValid(perNum, SIZE);

        // Check if input is valid and iterate until a correct personal number 
        while (!isValid(perNum, SIZE))
        {
            cout << "\nInvalid number, please enter the number in format: YYMMDD-XXXX: ";
            cin.getline(perNum,MAX);
        }

        // Find the size of the array 
        int arraySize = 0;
        while (perNum[arraySize] != '\0')
        {
            arraySize++;
        }

        // Check the cases where no "-" is used
        if (arraySize == 10)
        {   
            // Two cases for woman and man
            if (perNum[8] % 2 == 0)
            {
                cout << "The SSN " << perNum << " belongs to a woman";
            }else
            {
                cout << "The SSN " << perNum << " belongs to a man";
            }
        // Check the cases where "-" is used
        }else if (arraySize == 11)
        {
            // Two cases for woman and man
            if (perNum[9] % 2 == 0)
            {
                cout << "The SSN " << perNum << " belongs to a woman";
            }else
            {
                cout << "The SSN " << perNum << " belongs to a man";
            }
        }
        
        // Ask the user if he/she wants to retry
        cout << "\nWant to check another Social Security Number (Y/N)?: ";
        cin >> choice;
        cin.ignore();
    } while (toupper(choice) == 'Y');
}

// A function that checks if the input is correct
bool isValid(char array[],int size) 
{
    // Determining the size of the inputted array
    int arraySize = 0;
    while (array[arraySize] != '\0')
    {
        arraySize++;
    }
    
    // Case for personal numbers without "-"
    if (arraySize == size)
    {
        int count = 0;
        // Iterates until the end of the array and increases count by 1 whenever a digit is found
        for (int i = 0; i < 11; i++)
        {
            if (isdigit(array[i]))
            {
                count++;
            }
        }
        // Will return true if there are as many as 12 digits in the array
        if (count == size)
        {
            return true;
        }else
        {
            return false;
        }
    // Case for personal numbers with "-" 
    }else if (arraySize == size + 1 && array[6] == '-')
    {
        int count = 0;
        // Iterates until the end of the array and increases count by 1 whenever a digit is found
        for (int i = 0; i < 12; i++)
        {
            if (isdigit(array[i]))
            {
                count++;
            }
        }
        // Will return true if there are as many as 12 digits in the array
        if (count == size)
        {
            return true;
        }else
        {
            return false;
        }       
    }
    // Case which doesn't meet any criteria
    else
    {
        return false;
    }
}