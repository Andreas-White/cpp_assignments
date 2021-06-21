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

using namespace std;

int main()
{
    system("CLS");
    int count = 0;
    int size = 0;
    char *arr = new char[0];
    char arr1[100] = {'\0'};
    bool choice = true;

    cout << "Enter integer numbers to store (Stop by entering any non-numeric value): " << endl;
    

    do {
        cin.getline(arr,100);
        for (int i = 0; arr[i]; i++)
        {
            if (isalpha(arr[i]))
            {
                choice = false;
            }
            
        }
        if (!choice)
        {
            break;
        }
        
        char *temp = arr1;
        int count2 = count;
        for (int i = 0; arr[i]; i++)
        {
            count2++;
            arr1[count2 + i] = arr[i];
        }
        cout << arr1 << endl;
        //delete [] arr;
        
        count++;
    }while (choice);

    cout << "you entered " << count << " numbers: ";
    for (int i = 0; i < count; i++)
    {
        cout << arr1[i] << " ";
    }
    
    return 0;
}