//-----------------------------------------------------------------------
// File: InterestCalculato.cpp
// Summary: Reads two user's inputs, the initial amount of money and the   
// number of years being deposited and calculates the final capital plus 
// the interest
// Version: 1.1
// Owner: Andreas Manos
//-----------------------------------------------------------------------
// Log: 2020-11-12 Created the file, Andreas.
//-----------------------------------------------------------------------

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const double interest = 3;

// Prototypes
double inputCap();
double inputYears();
double calculate(double cap, double years);
void printRes(double finalCap);

int main()
{
    // initialising variables
    double capital = 0;
    double years = 0;
    char character;
    do
    {
        // calling the functions
        system("CLS");
        cout << "COMPOUND INTEREST" << endl << "==============\n\n";
        capital = inputCap();
        cout << endl;
        years = inputYears();
        cout << endl;
        double finalCap = calculate(capital, years);
        printRes(finalCap);
        cout << endl;

        cout << "Do you want to rerun (Y/N)?: ";
        cin >> character;
    } while (character == 'Y' || character == 'y');
    
    return 0;
}

// Function for reading capital
double inputCap()
{
    double cap = 0;
    cout << "Load initial amount: ";
    cin >> cap;
    return cap;
}

// Function for reading years
double inputYears()
{
    double years = 0;
    cout << "Load number of years: ";
    cin >> years;
    return years;
}

// Function for calculating the final capital
double calculate(double cap, double years) 
{
    double finalCap = 0;
    return finalCap += cap * pow((1 + interest / 100), years);
}

// Function for printing the results
void printRes(double finalCap)
{
    cout << "==========================================================" << endl;
    cout << fixed << setprecision(2) << showpoint;
    cout << "The capital with 3% interest rate and after 10 years will be: " << setw(12) << finalCap 
         << "SEK" << endl;
    cout << "==========================================================" << endl;

}