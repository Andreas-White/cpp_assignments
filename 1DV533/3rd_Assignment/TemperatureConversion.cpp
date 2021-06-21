//-----------------------------------------------------------------------
// File: TemperatureConversion.cpp
// Summary: Calculates the temperature in Celsius after reading the 
// corresponding one in Fahrenheit. In addition, prints out true if the
// degrees in Celsius are positive and false if not.
// Version: 1.1
// Owner: Andreas Manos
//-----------------------------------------------------------------------
// Log: 2020-11-23 Created the file, Andreas.
//-----------------------------------------------------------------------

#include <iostream>
#include <iomanip>

using namespace std;

// Prototype
bool fahrenheitToCelsius(double far, double &cel);

int main()
{
    // Define and initialize variables
    double far, cel;
    bool scale;
    char answer = 'Y';
    

    do
    {
        system("CLS");
        cout << "Temperature conversion" << endl;
        cout << "====================" << endl;
        cout << "Enter temperature in Fahrenheit: ";
        cin >> far;

        scale = fahrenheitToCelsius(far, cel);
        fahrenheitToCelsius(far, cel);

        cout << fixed << setprecision(1) << showpoint;
        cout << cel << " degrees Celsius" << endl;
        // In the statement bellow I use "boolalpha" in order to print true/false instead of 1/0
        cout << "Boolean value returned by the conversion function is: " << boolalpha << scale << endl;

        cout << endl << "One more time (Y/N)? ";
        cin >> answer;
    } while (toupper(answer) == 'Y');

    return 0;
}

// Has as arguments the given Fahrenheit degrees (pass by value) and the Celsius degrees (pass by reference)
// and returns true if the calculated value of Celsius degrees is more than 0 and false if not
bool fahrenheitToCelsius(double far, double &cel)
{
    cel = ((far - 32) * 5) / 9;
    if (cel > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}