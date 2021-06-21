//-----------------------------------------------------------------------
// File: Integers.cpp
// Summary: Reads an arbitrary number from a text file and prints the sum,
// mean value and max value of the integers
// Version: 1.1
// Owner: Andreas Manos
//-----------------------------------------------------------------------
// Log: 2021-1-4 Created the file, Andreas.
//-----------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <cassert>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Define and initialise variables
    double mean,num;
    double sum = 0; 
    int count = 0;
    int max = INT_MIN;

    // Create object for reading from txt file
    ifstream in;
    in.open("C:/Users/PC/OneDrive/Desktop/files/integers.txt");
    // Checking if the openned for reading
    assert(in.is_open());
    
    // Reading the integers from file and calculating sum, max and count
    while (in >> num)
    {
        sum += num;
        if (num > max)
        {
            max = num;
        }
        count++;
    }

    // Calculating mean value
    if (count > 1)
    {
        mean = sum / count;
    }
    
    // Printing the results
    cout << "Sum: " << sum << endl;
    cout << "Mean value: " << mean << endl;
    cout << "Max: " << max << endl;

    // Close file
    in.close();
    return 0;
}