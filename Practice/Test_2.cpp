//-----------------------------------------------------------------------
// File: MilitaryLanguage.cpp
// Summary: Reads a string and prints its abbreviation according to the
// given requirements/rules
// Version: 1.1
// Owner: Andreas Manos
//-----------------------------------------------------------------------
// Log: 2020-12-17 Created the file, Andreas.
//-----------------------------------------------------------------------

#include <iostream>
#include <string.h>
#include <cctype>

using namespace std;

bool isConsonant(char c);
int rmDupl(char *str);

const int MAX = 100;

int main()
{
    char str1[MAX] = {'\0'};
    char choice;

    do
    {
        system("CLS");
        cout << "Enter a term for abbreviation: ";
        cin.getline(str1,MAX);

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
        // Removing the remaining uneeded characters
        for (int i = count; str1[i]; i++)
        {
            str2[i] = '\0';
        }

        /*int count2 = 0;
        for (int i = 0; str2[i]; i++)
        {
            for (int j = i; j >= 0; j--)
            {
                if (str2[i] != str2[j])
                {
                    str2[count2] = str2[i];
                }else
                {
                    break;
                }
            }
            count2++;
        }
        
        // Removing the remaining uneeded characters
        for (int i = count2; str2[i]; i++)
        {
            str2[i] = '\0';
        }*/

        rmDupl(str2);
        cout << "\n" << str2 << endl;

        cout << "Want to retry? (Y/N): ";
        cin >> choice;
        cin.ignore();
    } while (toupper(choice) == 'Y');
    
    return 0;
}

bool isConsonant(char c)
{
    if (isalpha(c))
    {
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

int rmDupl(char *str)
{
    if (!str || !*str)
    {
        return 0;
    }
    
    int count[256] = {0};
    int cur = 0;
    int next = 0;
    
    while (str[cur] != '\0')
    {
        if (++count[str[cur]] == 1)
        {
            str[next++] = str[cur];
        }
        ++cur;
    }
    
    str[next] = '\0';

    return next;
    
}
