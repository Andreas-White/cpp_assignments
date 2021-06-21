//-----------------------------------------------------------------------
// File: PersonalInformation.cpp
// Summary: A program that reads the personal information of a user and 
// writes them in a text file
// multiplying them
// Version: 1.1
// Owner: Andreas Manos
//-----------------------------------------------------------------------
// Log: 2021-1-4 Created the file, Andreas.
//-----------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <cctype>
#include <cassert>

using namespace std;

const int SIZE = 100;

int main()
{
    // Define and initialise variables
    char choice;
    char arr[SIZE] = {'\0'};

    system("CLS");
    cout << "Enter personal information, and it will be saved to file: register.txt" << endl;

    do
    {
        cout << "Enter a name, phone number, and address, each separated by a comma:" << endl;

        // Reads the user's input 
        cin.getline(arr,SIZE);

        ofstream out("C:/Users/PC/OneDrive/Desktop/files/register.txt",ios::app); // appents at the end of the file

        // checks if the file is open fir writing
        assert(out.is_open());
        
        // Writes the user's input to the txt file
        out << arr << endl;

        // close the write object
        out.close();

        cout << "want to add more information: (y/n) ";
        cin >> choice;
        cin.ignore();
    } while (toupper(choice) == 'Y');
    
    return 0;
}