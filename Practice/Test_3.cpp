//-----------------------------------------------------------------------
// File: Backwards.cpp
// Summary: Reads a string and prints it in reverse
// Version: 1.1
// Owner: Andreas Manos
//-----------------------------------------------------------------------
// Log: 2020-12-15 Created the file, Andreas.
//-----------------------------------------------------------------------

#include <iostream>
#include <cctype>
#include <string.h>

using namespace std;

char* trim(char *str);

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

        char *newArray;
        
        newArray = trim(charArray);
        strcpy(newArray, charArray);
        cout << charArray;

        int count = 0;
        char secArray[MAX] = {'\0'};
        for (int i = 0; charArray[i]; i++)
        {
            if (isblank(charArray[i]) && isblank(charArray[i+1]))
            {
                continue;
            }else
            {
                secArray[count++] = charArray[i];
            }
        }
        strcpy(charArray,secArray);
        cout << "\n" << charArray;
        cout << "This";

        cout << "\nWant to retry? (Y/N): ";
        cin >> choice;
        cin.ignore();
    } while (toupper(choice) == 'Y');
    
    return 0;
} 

char* trim(char *str) 
{
    char* oldstr = str;

    while(*str==' '){
        str++;
    }

    char *str2 = oldstr;

    while(*str!='\0'){
        *(str2++) = *(str++);
    }
    *str2 = '\0';

    return oldstr;
}