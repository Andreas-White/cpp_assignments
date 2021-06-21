//-----------------------------------------------------------------------
// File: Discount.cpp
// Summary: A program that calculates the discount based on the given 
// paid amount
// Version: 1.1
// Owner: Andreas Manos
//-----------------------------------------------------------------------
// Log: 2020-11-25 Created the file, Andreas.
//-----------------------------------------------------------------------

// Include the standard libraries needed!
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Remember to declare all functions (prototypes)!
void load(double &sum);
void print(double sum, double discountKr);
double discount(double sum);

int main()
{
    double sum = 0.0, discountKr = 0.0;
    char answer;
    do {

        // write a statement to Clear Console Screen
        cout << "Discount" << endl;
        cout << "======" << endl << endl;
        load(sum);

        // To read the input sum from user – complete this function call,
        // by writing the necessary function definition!
        discountKr = sum * discount(sum) / 100;

        // To calculate the discount – complete the function call ("discount(sum)")
        // with a function definition
        sum = sum - discountKr;
        print(sum, discountKr);

        cout << endl << "One more time (Y/N)? ";
        cin >> answer;
    } while (toupper(answer) == 'Y');
    return 0;
}

// Add necessary function definitions here

void load(double &sum)
{
    cout << "Enter the sum: ";
    cin >> sum;
    
    // I included the while loop in case of negative input
    while (sum < 0)
    {
        cout << "Enter the sum: ";
        cin >> sum;
        cout << "Negative value, try again!";
    }
}

double discount(double sum)
{
    if (sum >= 0 & sum < 500)
    {
        return 0.0;
    }else if (sum >= 500 & sum < 1000)
    {
        return 5.0;
    }else if (sum >= 100 & sum < 5000)
    {
        return 10.0;
    }else
    {
        return 15.0;
    }
}

void print(double sum, double dKr)
{
    cout << "------------------------------------" << endl;
    cout << fixed << setprecision(2) << showpoint;
    cout << "Discount" <<setw(6) << setfill(' ') << ": " << setw(11) << setfill('.') << round(dKr)  << " kr" << endl;
    cout << "Net sum" <<setw(7) << setfill(' ') << ": " << setw(11) << setfill('.') << round(sum)  << " kr" << endl;
    cout << "------------------------------------" << endl;
}