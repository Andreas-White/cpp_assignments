//-----------------------------------------------------------------------
// File: Time.cpp
// Summary: Reads an arbitrary number from a text file and prints the sum,
// mean value and max value of the integers
// Version: 1.1
// Owner: Andreas Manos
//-----------------------------------------------------------------------
// Log: 2021-1-5 Created the file, Andreas.
//-----------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cassert>
#include <ctime>

using namespace std;

struct DataRecord
{
    char logger; // Define logging Point A, B, C, …
    double temp; // Logged Temperature
    time_t locTime; // Local Time
};

int main()
{
    // Initialize a DataRecord array 
    DataRecord dr[50];

    // Create an object for reading from a binary file
    ifstream in("C:/Users/PC/OneDrive/Desktop/files/timelog.dat",ios::binary);
    // Check if the file is open for reading
    assert(in.is_open());
    
    // Read the content of the binary file and assign it to the DataRecord array
    in.read((char*)&dr, sizeof dr);
    
    // Create an object for writing in a text file
    ofstream out("C:/Users/PC/OneDrive/Desktop/files/A.txt");
    // Check if the file is open for writing
    assert(out.is_open());

    // Writing the elements of the array in the A.txt
    out << "Data A" << endl;
    for (int i = 0; i < 50; i++)
    {
        if (dr[i].logger == 'A')
        {
            out << fixed << setprecision(1) << showpoint;
            out << dr[i].temp; 
            out << ", " << asctime(localtime(&dr[i].locTime));
        }
    }
    
    // Close files
    in.close();
    out.close();
    return 0;
}