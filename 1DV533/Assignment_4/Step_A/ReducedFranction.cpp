//-----------------------------------------------------------------------
// File: ReducedFraction.cpp
// Summary: Takes as input the numerator and the denominator of a fraction 
// and prints out the abbreviated form of it
// Version: 1.1
// Owner: Andreas Manos
//-----------------------------------------------------------------------
// Log: 2020-12-13 Created the file, Andreas.
//-----------------------------------------------------------------------

#include <iostream>

using namespace std;

// Prototypes
int gcd(int num1, int num2);

// Define structure Fraction
struct Fraction
{
    int numerator;
    int denumirator;
};


int main()
{
    // Define variables
    Fraction oldF, newF;
    int common;
    char choice;

    do
    {
        system("CLS");
        cout << "FRACTION CALCULATION" << endl;
        cout << "===========" << endl;

        // Ask the user for input
        cout << "Enter the numerator: ";
        cin >> oldF.numerator;
        cout << "\nEnter the denominator: ";
        cin >> oldF.denumirator;
        // Check that denominator is not equal to 0
        while (oldF.denumirator == 0)
        {
            cout << "\nDenumirator cannot be 0 enter another value: ";
            cin >> oldF.denumirator;
        }

        // Check if both inputs are positive integers
        if (oldF.numerator >= 0 && oldF.denumirator > 0)
        {
            common = gcd(oldF.numerator,oldF.denumirator);

            newF.numerator = oldF.numerator / common;
            newF.denumirator = oldF.denumirator / common;

            // Check if the fraction can abbreviated or not
            if (newF.numerator > newF.denumirator)
            {
                cout << "The fraction can be abbreviated to : " <<  newF.numerator << "/" << newF.denumirator;
                cout << " = " << newF.numerator / newF.denumirator << " " << newF.numerator % newF.denumirator << "/" << 
                newF.denumirator;
            }else 
            {
                cout << "\nThe fraction cannot be abbreviated";
            }
        }else
        {   
            // Check if both inputs are negative
            if (oldF.numerator < 0 && oldF.denumirator < 0)
            {
                int temp1 = oldF.numerator * -1;
                int temp2 = oldF.denumirator * -1;

                common = gcd(temp1,temp2);

                newF.numerator = temp1 / common;
                newF.denumirator = temp2 / common;

                // Check if the fraction can abbreviated or not
                if (newF.numerator > newF.denumirator)
                {
                    cout << "The fraction can be abbreviated to : " <<  newF.numerator << "/" << newF.denumirator;
                    cout << " = " << newF.numerator / newF.denumirator << " " << newF.numerator % newF.denumirator << "/" << 
                    newF.denumirator;
                }else 
                {
                    cout << "\nThe fraction cannot be abbreviated";
                }

             // Check if numerator is negative
            }else if (oldF.numerator < 0)
            {
                int temp1 = oldF.numerator * -1;

                common = gcd(temp1,oldF.denumirator);

                newF.numerator = temp1 / common;
                newF.denumirator = oldF.denumirator / common;

                // Check if the fraction can abbreviated or not
                if (newF.numerator > newF.denumirator)
                {
                    cout << "The fraction can be abbreviated to : " << "-" << newF.numerator << "/" << newF.denumirator;
                    cout << " = " << "-" << newF.numerator / newF.denumirator << " " << newF.numerator % newF.denumirator << "/" << 
                    newF.denumirator;
                }else 
                {
                    cout << "\nThe fraction cannot be abbreviated";
                }
             // Check if denominator is negative
            }else if (oldF.denumirator < 0)
            {
                int temp2 = oldF.denumirator * -1;

                common = gcd(oldF.numerator,temp2);

                newF.numerator = oldF.numerator / common;
                newF.denumirator = temp2 / common;

                // Check if the fraction can abbreviated or not
                if (newF.numerator > newF.denumirator)
                {
                    cout << "The fraction can be abbreviated to : " << "-" << newF.numerator << "/" << newF.denumirator;
                    cout << " = " << "-" << newF.numerator / newF.denumirator << " " << newF.numerator % newF.denumirator << "/" << 
                    newF.denumirator;
                }else 
                {
                    cout << "\nThe fraction cannot be abbreviated";
                }
            }
            
            
        }
        
        // Ask the user if he/she wants to retry
        cout << "\nWant to retry(Y/N)? : ";
        cin >> choice;
    } while (toupper(choice) == 'Y');
    
    
    return 0;
}

// The function calculates the greatest common divisor of two integers (but less than the smallest of the 
// two integers)
int gcd(int num1, int num2)
{
    if (num1 >= num2)
    {
        for (int i = num2; i >= 2; i--)
        {
            if (num2 % i == 0 && num1 % i == 0)
            {
                return i;
                break;
            }            
        }       
    }
    else if (num1 < num2)
    {
        for (int i = num1; i >= 2; i--)
        {
            if (num2 % i == 0 && num1 % i == 0)
            {
                return i;
                break;
            }           
        }        
    }else
    {
        return 1;   // If there is no greatest common divisor
    }   
}