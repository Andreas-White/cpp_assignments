//-----------------------------------------------------------------------
// File: SecondLargestValue.cpp
// Summary: Reads ten integers from the user and prints out the second
// largest value
// Version: 1.1
// Owner: Andreas Manos
//-----------------------------------------------------------------------
// Log: 2020-11-18 Created the file, Andreas.
//-----------------------------------------------------------------------

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int calc();

int main()
{
    char choice;

    do
    {
        // Prints out the second largest value after the 10 values are readed by the calc() function
        system("CLS");
        cout << "Give 10 integer values: " << endl;
        int secValue = calc();
        cout << "The second largest value is: " << secValue << endl;

        // Asking if the user wants to try more times
        cout << "Would you like to retry? (Y/N): ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');
    
    

    return 0;
}

// Reads 10 integers with a for-loop, calculates the largest and the second largest with the help
// of a nested if-statement and then returns the second largest value
int calc()
{
    int temp;
    int max = INT_MIN;
    int secMax = INT_MIN;

    for (int i = 0; i < 10; i++)
    {
        cin >> temp;
        cout << endl;
        if (temp > max)
        {
            secMax = max;
            max = temp;
        }
        else if (temp > secMax)
        {
            secMax = temp;
        }              
    }
    return secMax;
}