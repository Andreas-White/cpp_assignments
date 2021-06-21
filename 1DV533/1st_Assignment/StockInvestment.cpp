//-----------------------------------------------------------------------
// File: StockInvestment.cpp
// Summary: Reads two user's inputs, at first the initial capital as well 
// the years of investment and secondly the percentage of increase/decrease
// for each year. Finally, calculates and prints out the final capital. 
// Version: 1.1
// Owner: Andreas Manos
//-----------------------------------------------------------------------
// Log: 2020-11-07 Created the file, Andreas.
//-----------------------------------------------------------------------

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // Initialise the variables
    double capital = 0;
    int years = 0;
    double percentage = 0;
    char character;

    do
    {
        // Reads the user's input
        system("CLS");
        cout << "What is the initial capital: ";
        cin >> capital;
        cout << "\nFor how many years have you invested: ";
        cin >> years;

        system("CLS");
        cout << "==========================================================" << endl;

        // Iterates accordingly to user's input (years)
        for (int i = 0; i < years; i++)
        {
            // Reads the percentage of increase/decrease of the capital each year
            cout << "What was the percentage of increase/decrease of year " << i+1 << ": ";
            cin >> percentage;
            // Calculates the final Capital
            capital += capital * (percentage/100);
        }

        // Prints out the results
        cout << "==========================================================" << endl;
        cout << fixed << setprecision(2) << showpoint;
        cout << "The final capital is: " << capital << "SEK" << endl;
        cout << "==========================================================" << endl;

        cout << "Do you want to retry (Y/N): ";
        cin >> character;
    } while (character == 'Y' || character == 'y');
    
    return 0;
}
