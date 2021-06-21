//-----------------------------------------------------------------------
// File: Franctions.cpp
// Summary: A program that reads the dividends and divisors of two fractions
// and prints out the resulted fraction according to the mathematical 
// operation that was chosen
// Version: 1.1
// Owner: Andreas Manos
//-----------------------------------------------------------------------
// Log: 2020-11-26 Created the file, Andreas.
//-----------------------------------------------------------------------

#include <iostream>

using namespace std;

// Prototypes
void addF(int dent1, int dor1, int dent2, int dor2);
void subF(int dent1, int dor1, int dent2, int dor2);
void multF(int dent1, int dor1, int dent2, int dor2);
void divF(int dent1, int dor1, int dent2, int dor2);
int gcd(int num1, int num2);
bool CD(int num1, int num2);

int main()
{
    // Define and initialize variables
    int firDent = 0, firDor = 0, secDent = 0, secDor = 0, finDent = 0, finDor =0;
    char choice;
    char choice2;

    do
    {
        system("CLS");
        // Ask the user for inputs
        cout << "Enter first divident: ";
        cin >> firDent;
        cout << "\nEnter first divisor: ";
        cin >> firDor;
        cout << "\nEnter second divident: ";
        cin >> secDent;
        cout << "\nEnter second divisor: ";
        cin >> secDor;

        // Choosing the mathematical operation
        cout << "\nWhich mathematical operation do you want to apply\nfor addition(a)\nfor subtraction(s)";
        cout << "\nfor multiplication(m)\nfor division(d)\nEnter your choice here: ";
        cin >> choice2;
        cout << "\n\n";

        // Calling the functions according to the choice 
        if (toupper(choice2) == 'A')
        {
            addF(firDent,firDor,secDent,secDor);
        }
        else if (toupper(choice2) == 'S')
        {
            subF(firDent,firDor,secDent,secDor);
        }
        else if (toupper(choice2) == 'M')
        {
            multF(firDent,firDor,secDent,secDor);
        }
        else if (toupper(choice2) == 'D')
        {
            divF(firDent,firDor,secDent,secDor);
        }
        else
        {
            cout << "wrong inptut!";
        }
        
        
        cout << "\nWant to retry(Y/N)? : ";
        cin >> choice;
    } while (toupper(choice) == 'Y');
    
    return 0;
}

// The function adds the two fractions and prints out the new fraction
void addF(int dent1, int dor1, int dent2, int dor2)
{
    int findent = dent1 * dor2 + dent2 * dor1;
    int findor = dor1 * dor2;
    int lcD = 1;
    if (CD(findent,findor)) //check if thre's a common divisor
    {
        lcD = gcd(findent,findor); //find the greatest common divisor
    }
    cout << dent1 << "/" << dor1 << " + " << dent2 << "/" << dor2 << " = ";
    cout << findent/lcD << "/" << findor/lcD << endl;
}

// The function subtract the two fractions and prints out the new fraction
void subF(int dent1, int dor1, int dent2, int dor2)
{
    int findent = dent1 * dor2 - dent2 * dor1;
    int findor = dor1 * dor2;
    int lcD = 1;
    if (CD(findent,findor)) //check if thre's a common divisor
    {
        lcD = gcd(findent,findor); //find the greatest common divisor
    }
    cout << dent1 << "/" << dor1 << " - " << dent2 << "/" << dor2 << " = ";
    cout << findent/lcD << "/" << findor/lcD << endl;
}

// The function multiplies the two fractions and prints out the new fraction
void multF(int dent1, int dor1, int dent2, int dor2)
{
    int findent = dent1 * dent2;
    int findor = dor1 * dor2;
    int lcD = 1;
    if (CD(findent,findor)) //check if thre's a common divisor
    {
        lcD = gcd(findent,findor); //find the greatest common divisor
    }
    cout << dent1 << "/" << dor1 << " * " << dent2 << "/" << dor2 << " = ";
    cout << findent/lcD << "/" << findor/lcD << endl;
}

// The function divides the two fractions and prints out the new fraction
void divF(int dent1, int dor1, int dent2, int dor2)
{
    int findent = dent1 * dor2;
    int findor = dor1 * dent2;
    int lcD = 1;
    if (CD(findent,findor)) //check if thre's a common divisor
    {
        lcD = gcd(findent,findor); //find the greatest common divisor
    }
    cout << "(" << dent1 << "/" << dor1 << ")" << " / " << "(" << dent2 << "/" << dor2 << ")" << " = ";
    cout << findent/lcD << "/" << findor/lcD << endl;
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
    else 
    {
        for (int i = num1; i >= 2; i--)
        {
            if (num2 % i == 0 && num1 % i == 0)
            {
                return i;
                break;
            }           
        }        
    }
}

// The function checks if the two integers have a common divisor
bool CD(int num1, int num2)
{
    if (num1 > num2)
    {
        for (int i = 2; i < num2; i++)
        {
            if (num2 % i == 0 && num1 % i == 0)
            {
                return true;
                break;
            }            
        }       
    }
    else if (num1 < num2)
    {
        for (int i = 2; i < num1; i++)
        {
            if (num2 % i == 0 && num1 % i == 0)
            {
                return true;
                break;
            }           
        }        
    }
    else if (num1 == num2)
    {
        return true;
    }
    else
    {
        return false;
    }
}