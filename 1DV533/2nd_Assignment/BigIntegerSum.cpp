//-----------------------------------------------------------------------
// File: BigIntegerSum.cpp
// Summary: Reads an integer value and calculates and prints out the sum
// of its digits
// Version: 1.1
// Owner: Andreas Manos
//-----------------------------------------------------------------------
// Log: 2020-11-20 Created the file, Andreas.
//-----------------------------------------------------------------------

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Initialising variables
    char choice;
    const int max = INT_MAX;

    do
    {
        system("CLS");

        // Initialising variables inside the loop so they can restart with initial values
        double num;
        int sum = 0;

        // Proompt the user for input
        cout << "Insert an integer: ";
        cin >> num;

        // Checking if the input value is a positive integer less than 2.147.483.647
        // and displaying the error message
        if (num > max || num < 0)
        {
            cout << "Wrong input, try another integer between 0 and 2.147.483.647" << endl;
        }
        else
        {
            // Calculating the sum of the digits of the input value
            while (num > 0) 
            {
                sum += (int) num % 10;
                num = num /10;
            }

            // Printing the results
        cout << "The sum of the digits is: " << sum << endl;
        }
    
        // Asking if the user wants to try more times
        cout << "Would you like to retry? (Y/N): ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');
    
    return 0;
}