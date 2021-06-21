#include <iostream>
#include <cctype>
#include <iomanip>
#include <cmath>
#include <string.h>

using namespace std;

int main()
{
    system("CLS");

    char str1[] = "                   Hello               World               !          ";
    char *str2 = str1;

    int count = 0;
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
    for (int i = 0; str2[i]; i++)
    {
        count1++;
    }

    int count2 = 0;
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
    cout << str1;
    cout << "This";
}