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
#include <cctype>
#include <cassert>

using namespace std;

int main()
{
    char c;

    // Create an object for reading from a binary file
    ifstream in("C:/Users/PC/OneDrive/Desktop/files/abcfile.dat",ios::binary);
    // Create two objects for writing in two different text files
    ofstream outLower("C:/Users/PC/OneDrive/Desktop/files/lower.txt");
    ofstream outUpper("C:/Users/PC/OneDrive/Desktop/files/upper.txt");

    // Check if the files are open for reading and writing respectively
    assert(in.is_open());
    assert(outLower.is_open());
    assert(outUpper.is_open());

    while (in.get(c))
    {
        // If input char is lowercase write it in lower.txt
        if (isupper(c))
        {
            outUpper << c << " ";
        }

        // If input char is uppercase write it in upper.txt
        if (islower(c))
        {
            outLower << c << " ";
        }
        
        // If end of file is reached break (I think this is redundant)
        if (in.eof())
        {
            break;
        }
        
    }
    
    // Close files
    in.close();
    outLower.close();
    outUpper.close();

    return 0;
}