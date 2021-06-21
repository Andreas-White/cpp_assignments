//-----------------------------------------------------------------------
// File: Integers.cpp
// Summary: Reads an arbitrary number from a text file and prints the sum,
// mean value and max value of the integers
// Version: 1.1
// Owner: Andreas Manos
//-----------------------------------------------------------------------
// Log: 2020-12-26 Created the file, Andreas.
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
    DataRecord dr[50];
    const int WIDTH = 2;

    ifstream in("C:/Users/PC/OneDrive/Desktop/files/timelog.dat",ios::binary);
    assert(in.is_open());
    
    in.read((char*)&dr, sizeof dr);
    
    ofstream out("C:/Users/PC/OneDrive/Desktop/files/A.txt");
    assert(out.is_open());

    out << "Data A" << endl;
    for (int i = 0; i < 50; i++)
    {
        if (dr[i].logger == 'A')
        {
            out << fixed << setprecision(1) << showpoint;
            out << dr[i].temp; 
            out << ", " << asctime(localtime(&dr[i].locTime)) << endl;
        }
    }
    
    in.close();
    out.close();
    return 0;
}