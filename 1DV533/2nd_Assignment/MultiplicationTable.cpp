//-----------------------------------------------------------------------
// File: MultiplicationTable.cpp
// Summary: Creates a table with values from 1 until 15
// Version: 1.1
// Owner: Andreas Manos
//-----------------------------------------------------------------------
// Log: 2020-11-17 Created the file, Andreas.
//-----------------------------------------------------------------------

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    system("CLS");

    // Printing out the headers
    cout << "Multiplication table" << endl << "=====================" << endl;
    cout << "n" << setw(8) << "10*n" << setw(8) << "100*n" << setw(8) << "1000*n" << endl;
    cout << "---------------------------" << endl;

    // Prints each line by using a for loop
    for (int i = 1; i <= 15; i++)
    {
        cout << i << setw(8) << i * 10 << setw(8) << i * 100 << setw(8) << i * 1000 << endl;
    }
    
}