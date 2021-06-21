//-----------------------------------------------------------------------
// File: Backwards.cpp
// Summary: Reads a string and prints it in reverse
// Version: 1.1
// Owner: Andreas Manos
//-----------------------------------------------------------------------
// Log: 2020-12-15 Created the file, Andreas.
//-----------------------------------------------------------------------

#include <iostream>

using namespace std;

const int MAX = 100;

int main()
{
    char choice;
    char charArray[MAX] = {'\0'};
    do
    {
        system("CLS");
        
        // Asking for input
        cout << "Enter a text: ";
        cin.getline(charArray, MAX);

        // Calculating the lenght of the array
        int count = 0;
        for (int i = 0; charArray[i]; i++)
        {
            count++;
        }

        char str[count] = {'\0'};
        // Storing the String in reverse to the new created string      
        for (int i = 0; i < count; i++)
        {
            str[count -1 -i] = *(charArray + i);
        }
        cout << str;
        
        cout << "\nWant to retry? (Y/N): ";
        cin >> choice;
        cin.ignore();
    } while (toupper(choice) == 'Y');
    
    return 0;
}