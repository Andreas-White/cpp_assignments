//-----------------------------------------------------------------------
// File: Trim.cpp
// Summary: Reads a string and removes all the leading and trailing white-
// spaces, as well as the more than one whitespaces in between the words
// Version: 1.1
// Owner: Andreas Manos
//-----------------------------------------------------------------------
// Log: 2020-12-17 Created the file, Andreas.
//-----------------------------------------------------------------------

#include <iostream>
#include <string.h>

using namespace std;

const int MAX = 100;

int main()
{
    char choice;
    char str1[MAX] = {'\0'};
    do
    {
        system("CLS");
        
        // Asking for input
        cout << "Enter a text: ";
        cin.getline(str1, MAX);

        char *str2 = str1;

        int count = 0;
        //Here I remove all the leading spaces and in between that are more than one, as well as the trailing ones except one
        for (int i = 0; str1[i]; i++)   
        {
            if (isblank(str1[i]) && isblank(str1[i+1]))
            {
                continue;
            }else
            {
                str2[count++] = str2[i+1];
            }
        }

        int count1 = 0;
        for (int i = 0; str2[i]; i++)   // Calculating the lenght of str2
        {
            count1++;
        }

        int count2 = 0;
        // Here I remove the single trailing space and append '\0'
        for (int i = 0; i < count1-1; i++)
        {
            if (i == count1 - 2)
            {
                str2[count1-1] = '\0';
                break;
            }
            str2[count2++] = str2[i];
        }
        strcpy(str1,str2);
        // Notice there is a space after 'Cleared text:_' but no leading space in str1 
        cout << "Cleared text: " << str1;
        
        cout << "\nWant to retry? (Y/N): ";
        cin >> choice;
        cin.ignore();
    } while (toupper(choice) == 'Y');
    
    return 0;
}       