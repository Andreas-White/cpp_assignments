//-----------------------------------------------------------------------
// File: SumIntegers.cpp
// Summary: Reads a three- digit integer and calculates and prints 
// the sum of the three digits that the integer consist of
// Version: 1.1
// Owner: Andreas Manos
//-----------------------------------------------------------------------
// Log: 2020-11-05 Created the file, Andreas.
//-----------------------------------------------------------------------

#include <iostream>

using namespace std;

int main()
{
    // Define and initialize variables
    int num = 0;
    char character;

    do
    {
        system("CLS");
        // Read the integer from user
        cout << "Enter a three- digit integer: " << endl;
        cin >> num;

        // Calculate the sum of the three digits
        int num1 = num / 100;
        int num2 = (num % 100) / 10;
        int num3 = num % 10;
        int sum = num1 + num2 + num3;
        
        // Display the sum
        cout << "The sum of the three digits of which the integer consists of is: " << sum << endl;

        cout << "Do you want to try again? (Y/N): " << endl;
        cin >> character;
    } while (!(character == 'N' || character == 'n'));
    
    return 0;
}