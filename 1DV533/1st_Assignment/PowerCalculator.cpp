//-----------------------------------------------------------------------
// File: PowerCalculator.cpp
// Summary: Reads two values in watts and calculates and 
// prints the increase in decibel as well as the impact of that
// increase to us regarding accoustic
// Version: 1.1
// Owner: Andreas Manos
//-----------------------------------------------------------------------
// Log: 2020-11-05 Created the file, Andreas.
//-----------------------------------------------------------------------

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    // Define and initialize variables
    double power1 = 0;
    double power2 = 0;
    double dB = 0;
    char character;

    do
    {
        system("CLS");

        // Read the values from user
        cout << "Give the first power: ";
        cin >> power1;
        cout << "Give the second power: ";
        cin >> power2;

        // Calculate the decibel
        dB = 10 * log10(power2 / power1);

        system("CLS");
        // Display decibels
        cout << "POWER CALCULATIONS" << endl;
        cout << "=================" << endl;
        cout << "Sound Power P0: " << (int) power1 << endl << "Increased Sound Power P1: " 
             << (int) power2 << endl;
        cout << "=============================" << endl;
        cout << fixed << setprecision(1) << showpoint;
        cout << "A change from " << power1 << " to " << power2 << " corresponds to " << dB << " dB" << endl;
        cout << "That is " << (int) dB / 3 << " level of 3dB" << endl;

        cout << "One more time? (Y/N): " << endl;
        cin >> character;
    } while (character == 'Y' || character == 'y');
    
    return 0;
}