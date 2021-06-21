//-----------------------------------------------------------------------
// File: MilitaryLanguage.cpp
// Summary: Reads a string/term and prints its abbreviation form according
// to the given requirements/rules
// Version: 1.1
// Owner: Andreas Manos
//-----------------------------------------------------------------------
// Log: 2020-12-18 Created the file, Andreas.
//-----------------------------------------------------------------------

#include <iostream>
#include <string.h>
#include <cctype>

using namespace std;

// Prototype
bool isConsonant(char c);

const int MAX = 100;

int main()
{
    // Define and initialise variables
    char str1[MAX] = {'\0'};
    char choice;

    do
    {
        system("CLS");
        // Asking the user for input
        cout << "Enter a term for abbreviation: ";
        cin.getline(str1,MAX);
        char str3[MAX] = {'\0'};
        // Coping str1 to str3, so it can be used in the end
        strcpy(str3,str1);
        // Pointing str2 to str1
        char *str2 = str1;
        
        // Assigning only the consonants to str2
        int count = 0;
        for (int i = 0; str1[i]; i++)
        {
            if (isConsonant(str1[i]))
            {
                str2[count++] = str1[i];
            }
            else if (!isConsonant(str1[i]))
            {
                continue;
            }
        }
        // Removing the remaining uneeded consonants
        for (int i = count; str1[i]; i++)
        {
            str2[i] = '\0';
        }

        // Removing double consonants
        int count2 = 0;
        for (int i = 0; str2[i]; i++)
        {
            if (str2[i] == str2[i+1])
            {
                str2[count2] = '\0';
            }else
            {
                str2[count2++] = str2[i];
            }
        }
        
        // Removing the remaining uneeded consonants
        for (int i = count2; str2[i]; i++)
        {
            str2[i] = '\0';
        }

        // Printing the results according to the length of str2
        if (count2 > 5)
        {
            cout << str3 << " -> ";
            for (int i = 0; i < 3; i++)
            {
                cout << str2[i];
            }
            for (int i = count2 - 2; i < count2; i++)
            {
                cout << str2[i];
            }
            cout << endl;
        }else
        {
            cout << str3 << " -> " << str2 << endl;
        }

        cout << "Want to retry? (Y/N): ";
        cin >> choice;
        cin.ignore();
    } while (toupper(choice) == 'Y');
    
    return 0;
}

// A function for checking if a character is a consonant
bool isConsonant(char c)
{
    // Checking if the character is alphabetic
    if (isalpha(c))
    {
        // Excluding vowels
        if (tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'u' || tolower(c) == 'i' || tolower(c) == 'o' || 
        tolower(c) == 'å' || tolower(c) == 'ö' || tolower(c) == 'ä')
        {
            return false;
        }
        else
        {
            return true;
        }
    }else
    {
        return false;
    }   
}
