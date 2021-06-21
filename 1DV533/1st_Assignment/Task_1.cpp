// File: PayIncrease.cpp
// Summary: This program calculates the new salary and
// retroactive pay following a raise.
// Version: 1.1
// Owner: Tommy Löfqvist
// -------------------------------------------
// Log: 2005-03-10 Created the file. Mats
// 2009-08-14 Modified by Tommy Löfqvist.
// Removal of unnecessary code. Added iteration of the calculations.
// 2012-10-22 Revised by Anne. Converted to English and VS 2012
// Preprocessor directives

#include <iostream>
#include <iomanip>

using namespace std;

// Constants
const double PERCENT = 2.6;
const double FACTOR = PERCENT/100;

int main()
{
    // Define and initialize variables
    int monthlyWage = 0;
    int newMonthlyWage = 0;
    int retroactiveWage = 0;
    char answer;
    do
    {

        // Load the monthly salary from the user
        system("CLS"); // Clear the screen
        cout << "PAY RAISE\n";
        cout << "==============\n\n";
        cout << "Input monthly wage : ";
        cin >> monthlyWage;
        cin.ignore(80,'\n'); // Skip any possible debris and line endings

        // Calculate new monthly salary and retroactive pay
        newMonthlyWage = int(monthlyWage * (1 + FACTOR) + 0.5);
        retroactiveWage = int(monthlyWage * FACTOR * 6 + 0.5);

        // Display results
        cout << "===========================" << endl;
        cout << "New monthly wage : " << setw(6) << newMonthlyWage << " kr" << endl
        << "Retroactive wage : " << setw(6) << retroactiveWage << " kr" << endl;
        cout << "\n\nNew calculation (Y/N)?";
        cin >> answer;
    }while (answer == 'Y' || answer == 'y');
    return 0;
}
