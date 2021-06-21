//-----------------------------------------------------------------------
// File: Backwards.cpp
// Summary: Reads the full name of people and prints the first letter of
// the firstname and the full last name
// Version: 1.1
// Owner: Andreas Manos
//-----------------------------------------------------------------------
// Log: 2020-12-15 Created the file, Andreas.
//-----------------------------------------------------------------------

#include <iostream>
#include <cctype>

using namespace std;

const int MAX = 100;

int main()
{
    // Initialise variables
    char choice;
    char charArray[MAX] = {'\0'};
    do
    {
        system("CLS");
        
        // Asking for input
        cout << "Enter a full name: ";
        cin.getline(charArray, MAX);

        // Spotting the exact location of the whitespace
        int space = 0;
        for (int i = 0; charArray[i]; i++)
        {
            if (isblank(charArray[i]))
            {
                space = i;
            }
        }

        // Calculating the lenght of the array
        int count = 0;
        for (int i = 0; charArray[i]; i++)
        {
            count++;
        }

        cout << "Treated name: ";
        // Prints the first letter of the firstname  
        cout << *charArray << " ";  
        // Prints the lastname, beginning after the whitespace 
        for (int i = space + 1; i < count; i++)
        {
            cout << *(charArray + i);
        }
        
        cout << "\nWant to retry? (Y/N): ";
        cin >> choice;
        cin.ignore();
    } while (toupper(choice) == 'Y');
    
    return 0;
}