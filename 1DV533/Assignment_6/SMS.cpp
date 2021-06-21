//-----------------------------------------------------------------------
// File: SMS.cpp
// Summary: Reads a text file containing the logs of sended and received 
// messages and filters it to the specified sender's phone number
// Version: 1.1
// Owner: Andreas Manos
//-----------------------------------------------------------------------
// Log: 2021-1-6 Created the file, Andreas.
//-----------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <cassert>
#include <string>

using namespace std;

// Prototypes
bool senderFilter(char *logFileName, char *resultFileName, const char *sender);

const int SIZE = 255;

int main()
{
    // Initialize the wanted strings
    char send[] = "0703-124566";
    char log[] = "C:/Users/PC/OneDrive/Desktop/files/smslog_eng.txt";
    char result[] = "C:/Users/PC/OneDrive/Desktop/files/newFile.txt";

    // Use senderFilter and assing the returned value to newF 
    bool newF = senderFilter(log,result,send);

    // Use the newF to print accordingly
    if (newF)
    {
        cout << "Writing was successful";
    }
    else
    {
        cout << "Error while writing";
    }
    
    return 0;
}

// A fuction that reads and writes two files according to the arguments
bool senderFilter(char *logFileName, char *resultFileName, const char *sender)
{
    // Initialize objects and variables
    ifstream in(logFileName);
    ofstream out(resultFileName);
    string logs[SIZE];
    int count = 0;

    // Check if files are open for read/write operations respectively
    assert(in.is_open());
    assert(out.is_open());

    // Store each line of the text file in an array of strings (I used strings instead of char arrays, since there is not
    // a restriction and they are easier to use)
    while (!in.eof())
    {
        getline(in,logs[count]);
        count++;
    }

    // Create a string from the sender char array
    string senderS = ""; 
    for (int i = 0; sender[i]; i++) { 
        senderS = senderS + sender[i]; 
    }

    // Writing the wanted strings to the new file
    for (int i = 0; i < count; i++)
    {
        if (i % 4 == 0 && logs[i].compare(senderS) == 0)
        {
            out << logs[i] << endl;
            out << logs[i+1] << endl;
            out << logs[i+2] << endl;
            out << logs[i+3] << endl;
        }
    }

    if (out.is_open())
    {
        // If the new file was open and written I close both files and return true
        in.close();
        out.close();
        return true;
    }
    else
    {
        return false;
    }
}