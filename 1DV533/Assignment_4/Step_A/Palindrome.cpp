//-----------------------------------------------------------------------
// File: Palindrome.cpp
// Summary: Reads a character array/string from a user and determines if
// it is a palindrome or not
// Version: 1.1
// Owner: Andreas Manos
//-----------------------------------------------------------------------
// Log: 2020-12-14 Created the file, Andreas.
//-----------------------------------------------------------------------

#include <iostream>
#include <cctype>

using namespace std;

// Prototype
bool isPalindrome(char array[]);

// Max size of the array
const int SIZE = 100;

int main()
{
    // Initialise variables
    char choice;
    char phrase[] = {'\0'};

    do
    {
        system("CLS");

        // Ask user for input
        cout << "Enter a word or phrase: ";
        cin.getline(phrase,SIZE);

        // Prints the result according to the isPalindrome function
        if (isPalindrome(phrase))
        {
            cout << "It is a palindrome." << endl;
        }else
        {
            cout << "It is not a palindrome." << endl;
        }

        cout << "\nWant to retry? (Y/N): ";
        cin >> choice;
        cin.ignore();
    } while (toupper(choice) == 'Y');
    
    return 0;
}

// A function that checks if the phrase is a palindrome
bool isPalindrome(char array[])
{
    int size = 0;
    // Remove whitespaces 
    for (int i = 0; array[i]; i++) 
    {
        if (array[i] != ' ') 
        {
            array[size++] = array[i]; // here count is incremented
        }
    }

    array[size] = '\0';

    int count = 0;
    // Increment count according to the same characters in the array and each reverse
    for (int i = 0; i < size; i++)
    {
        if (tolower(array[i]) == tolower(array[(size - 1) - i]))
        {
            count++;
        }       
    }
    
    // If the array size is the same as the number of matches return true
    if (count == size)
    {
        return true;
    }else
    {
        return false;
    }   
}