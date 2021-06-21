//-----------------------------------------------------------------------
// File: Backwards.cpp
// Summary: Reads a string and prints it in reverse
// Version: 1.1
// Owner: Andreas Manos
//-----------------------------------------------------------------------
// Log: 2020-12-15 Created the file, Andreas.
//-----------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <cassert>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

const int SIZE = 255;

int main()
{
     // Define and initialise variables
    double mean,num;
    double sum = 0, sum2 = 0,Ra = 0, Rq = 0; 
    int count = 0;
    double max = INT_MIN;
    double min = INT_MAX;

    // Create object for reading from txt file
    ifstream in;
    in.open("C:/Users/PC/OneDrive/Desktop/files/surfacedata.txt");
    // Checking if the openned for reading
    assert(in.is_open());
    
    // Reading the integers from file and calculating sum, max and count
    while (in >> num)
    {
        if (num < 0)
        {
            sum += (-num);
        }else
        {
            sum += num;
        }
        
        sum2 += pow(num,2);
        if (num > max)
        {
            max = num;
        }
        if (num < min)
        {
            min = num;
        }
        count++;
    }

    double mrh = (-min) + max;

    Ra = sum / count;
    Rq = sqrt(sum2/count);

    cout << fixed << setprecision(3) << showpoint;
    cout << "Ra                   =      " << Ra << endl;
    cout << "Rq                   =      " << Rq << endl;
    cout << "Max Roughness height =      " << mrh << endl;
    cout << "Numbers of values    =        " << count << endl;
    cout << "Done!";

    return 0;
}       