//-----------------------------------------------------------------------
// File: ScatingScore.cpp
// Summary: Reads ten judgments scores (double values) from the user and 
// prints out the average score after removing the highest and lowest score
// Version: 1.1
// Owner: Andreas Manos
//-----------------------------------------------------------------------
// Log: 2020-11-19 Created the file, Andreas.
//-----------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;
double calcSrore();

int main()
{
    char choice;
    do
    {
        system("CLS");

        // Prints out the final score
        cout << "Give the judgments: " << endl;
        double finalScore = calcSrore();
        cout << fixed << setprecision(1) << showpoint;
        cout << "The final score is: " << finalScore << endl;

        // Asking if the user wants to try more times
        cout << "Would you like to retry? (Y/N): ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');
    
    return 0;
}

// Calculate the average of the scores after removing lowest and highest
double calcSrore()
{
    // Initialising variables
    double temp;
    double max = INT_MIN;
    double min = INT_MAX;
    double sum = 0;

    // Computing min, max and sum
    for (int i = 0; i < 9; i++)
    {
        cin >> temp;
        cout << endl;

        if (temp > max)
        {
            max = temp;
        }

        if (temp < min)
        {
            min = temp;
        }
        
        sum += temp;
    }

    // Calculates and returns the average
    return (sum - max -min) / 7;
}