// File: FourNumbers.cpp
// Summary: This program calculates the sum, average and product of
// four integers
// Version: 1.1
// Owner: Tommy Löfqvist
//-----------------------------------------------
// Log:
// 2005-03-10 Created the file. Mats
// 2009-08-15 Modified by Tommy Löfqvist. Added iteration of program.
// 2012-10-27 Revised by Anne. Converted to English and VS 2012
// Preprocessor directives

#include <iostream> //cin cout endl
#include <iomanip> //setw fixed setprecision

using namespace std;

//Prototypes
void statistics();

int main()
{
    char answer;
    do
    {
        statistics();
        cout << "One more time (Y/N) ?";
        cin >> answer;
    } while (answer =='Y' || answer == 'y');
    return 0;
}

void statistics()
{
    // Define and initialize variables
    int nr1, nr2, nr3, nr4;
    int sum = 0;
    double average = 0; // Average value may contain decimals => double
    double product = 0; // The product may be large => double

    // Read the values from user
    system("CLS"); // Clear screen
    cout << "STATISTICS" << endl;
    cout << "==========" << endl << endl;
    cout << "Input four integers: ";
    cin >> nr1 >> nr2 >> nr3 >> nr4;

    // Calculate sum, average and product
    sum = nr1 + nr2 + nr3 + nr4;
    average = sum / 4.0; // NOTE! 4.0 to avoid integer division
    product = nr1 * nr2 * nr3 * nr4;

    // Display results
    cout << fixed << showpoint; // Decimal form, display trailing zeroes
    cout << endl << "Entered integers "
    << setw(8) << nr1
    << setw(8) << nr2
    << setw(8) << nr3
    << setw(8) << nr4 << endl << endl;
    cout << setw(8) << "Sum" << setw(12) << "Average" << setw(12) << "Product\n"
    << setw(8) << "---" << setw(12) << "-------" << setw(12) << "-------\n"
    << setw(8) << sum
    << setw(12)<< setprecision(2) << average
    << setw(12)<< setprecision(0) << product << endl << endl;
}