//-----------------------------------------------------------------------
// File: Integers.cpp
// Summary: Reads an arbitrary number of integers and a non numeric value
// value is entered, then prints the amount of integers and the integers
// themselves
// Version: 1.1
// Owner: Andreas Manos
//-----------------------------------------------------------------------
// Log: 2020-12-26 Created the file, Andreas.
//-----------------------------------------------------------------------

#include <iostream>

using namespace std;

int main()
{
    system("CLS");
    int count = 0;
    int *arr = new int[0];
    int num = 0;
    

    cout << "Enter integer numbers to store (Stop by entering any non-numeric value): " << endl;
    

    do {
        cin >> num;

        if (num == NULL)
        {
            break;
        }
        count++;
        int *temp = new int[1];
        for (int i = 0; i < count; i++)
        {
            temp[i] = arr[i];
        }
        temp[count-1] = num;
        delete [] arr;
        arr = temp;

    /*I tried to distinguish char from int with the value of the variable, but this doesn't work if the input is 0.
    My first attempt was with sizeof function but even if the inputted variable was a char it still read it as int and allocate
    4 bytes size to it, so it wouldn't distinguish char from int. My second attempt was to read the input as char and use the 
    isdigit() function, however the problem was it read int with more than 1 digit as different inputs, so I ended with 
    defining the input by value (since char input would be equal to zero), as it would be closer to the requirements.*/
    }while (num != NULL);

    cout << "you entered " << count << " numbers: ";

    for (int i = 0; i < count; i++)
    {
        cout << arr[i] << " ";
    }

    delete [] arr;
    return 0;
}