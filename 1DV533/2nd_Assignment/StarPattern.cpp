//-----------------------------------------------------------------------
// File: StarPattern.cpp
// Summary: Creates a specific star pattern
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

    // a nested for-loop for accessing the rows and columns 
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j <= 8; j++)
        {
            // a nested if-statement for controlling when to print stars(*) and empty spaces(" ")
            if (i % 2 == 0)
            {
                if (j < 8)
                {
                    cout << "* ";
                }
                else
                {
                    cout << " ";
                }               
            }

            else if (i % 2 == 1)
            {
                if (j == 0)
                {
                    cout << " ";
                }
                else
                {
                    cout << "* ";
                } 
            }          
        }

        // for changing the line
        cout << endl;       
    }   
}