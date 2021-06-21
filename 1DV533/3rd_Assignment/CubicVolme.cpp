//-----------------------------------------------------------------------
// File: CubicVolume.cpp
// Summary: Calculates the cubic volume by reading a side as a double 
// value
// Version: 1.1
// Owner: Andreas Manos
//-----------------------------------------------------------------------
// Log: 2020-11-23 Created the file, Andreas.
//-----------------------------------------------------------------------

#include <iostream>
#include <cctype>

using namespace std;

// Prototypes
double read();
double calculate(double side);
void print(double volume);

int main()
{   
    // Initialize variables
    double side = 0.0, volume = 0.0;
    char answer = 'Y';

    cout << "Cubes" << endl;
    cout << "=====" << endl << endl;

    do
    {
        system("CLS");
        side = read();
        volume = calculate(side);
        print(volume);

        // Checking if the user wants to rerun the program
        cout << endl << "One more time (Y/N)? ";
        cin >> answer;
    } while (toupper(answer) == 'Y');

    return 0;
}

// Read side
double read()
{
    double side;
    cout << "Enter the side length of a cube to be computed: ";
    cin >> side;
    return side;
}

// Calculate volume
double calculate(double side)
{
    return side * side * side;
}

// Print volume
void print(double volume)
{
    cout << "Volume of the cube is: " << volume << " volume units" << endl;
}