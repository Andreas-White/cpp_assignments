//-----------------------------------------------------------------------
// File: OddIntegers.cpp
// Summary: The program prints out the product of all odd integers 
// between 1 and 15
// Version: 1.1
// Owner: Andreas Manos
//-----------------------------------------------------------------------
// Log: 2020-11-17 Created the file, Andreas.
//-----------------------------------------------------------------------

#include <iostream>

using namespace std;

int main()
{
    system("CLS");
    // initialise integer
    int product = 1;

    // calculate the product of odd integers
    for (int i = 1; i <= 15; i++)
    {
        if (i % 2 == 1)
            product *=  i;
    }

    // prints out the result
    cout << "The product is: " << product << endl;

    return 0;
}