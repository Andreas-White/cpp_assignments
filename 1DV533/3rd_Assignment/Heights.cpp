//-----------------------------------------------------------------------
// File: Heights.cpp
// Summary: Reads the gender of the child, as well as his mother's height
// and farther's and finally prints out the child's height based on his/her
// gender
// Version: 1.1
// Owner: Andreas Manos
//-----------------------------------------------------------------------
// Log: 2020-11-24 Created the file, Andreas.
//-----------------------------------------------------------------------

#include <iostream>
#include <iomanip>

using namespace std;

// prototype
double childHeight(char g, double hm, double hf);

int main()
{
    // define variables
    double heightM, heightF;
    char gender;
    char choice;

    do
    {
        system("CLS");

        // Prompts the user for inputs
        cout << "Enter the gender of the child (F for female/ M for male): ";
        cin >> gender;
        cout << "\nEnter the height of the mother: ";
        cin >> heightM;
        cout << "\nEnter the height of the father: ";
        cin >> heightF;

        // calculates the height of the child
        double childH = childHeight(gender,heightM,heightF);
        cout << fixed << setprecision(1) << showpoint;
        cout << "The height of the child is: " << childH << " cm" << endl;

        // ask the user for rerunning the program
        cout << endl << "One more time (Y/N)? ";
        cin >> choice;
    } while (toupper(choice) == 'Y');
    
}

// a function that has as parameters the gender, the height of the mother and the height of the father
// and returns the height of the child according to his gender
double childHeight(char g, double hm, double hf)
{
    if (toupper(g) == 'F')
    {
        return ((hf * 12/13) + hm) / 2;
    }
    else
    {
        return ((hm * 13/12) + hf) / 2;
    }
}