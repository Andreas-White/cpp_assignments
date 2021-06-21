//-----------------------------------------------------------------------
// File: DiverScore.cpp
// Summary: Takes as input the difficulty level and seven judgments scores 
// (double values) from the user and prints out the average score after 
// removing the highest and lowest score
// Version: 1.1
// Owner: Andreas Manos
//-----------------------------------------------------------------------
// Log: 2020-12-12 Created the file, Andreas.
//-----------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

// Prototype
double calcSrore(double array[], double sc);

// Constant for array size
const int size = 7;

int main()
{
    system("CLS");

    // Define and initialise variables
    double diffLevel = 0.0;
    double scores[size] = {'\0'};
    double finalScore = 0.0;

    // Asks the user to input the difficulty level
    cout << "Enter the degree of difficulty for the dive (1.0 - 4.0): ";
    cin >> diffLevel;
    // Checks the input for the correct range
    while (!(diffLevel > 1.0 && diffLevel <= 4.0))
        {
            cout << "\nWrong inptut! Enter again the degree of difficulty for the dive (1.0 - 4.0): ";
            cin >> diffLevel;
        }

    // Iterates until the array length
    for (int i = 0; i < size; i++)
    {
        double score = 0.0;
        // Asks the user for the scores 
        cout << "\nEnter score for judge" << i + 1 << "(0-10): ";
        cin >> score;
        // Checks if the scores are in the correct range
        while (!(score > 0 && score <= 10))
        {
            cout << "\nWrong inptut! Enter again score for judge" << i + 1 << "(0-10):";
            cin >> score;
        }
        
        scores[i] = score;
    }

    finalScore = calcSrore(scores,diffLevel);

    // Prints the final score
    cout << fixed << setprecision(2) << showpoint;
    cout << "The diver's final score is " << finalScore << endl;
    
    return 0;
}

// Calculates the final score
double calcSrore(double array[], double sc)
{
    // Initialising variables
    double temp;
    double max = INT_MIN;
    double min = INT_MAX;
    double sum = 0;

    // Computing min, max and sum
    for (int i = 0; i < size; i++)
    {
        temp = array[i];

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

    // Calculates and returns the final score
    return ((sum - max -min) * sc) * 0.6;
}