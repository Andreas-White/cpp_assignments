//-----------------------------------------------------------------------
// File: TimeCalculator.cpp
// Summary: Reads the remaining distance in Swedish miles and average speed in km/h. 
// Calculates and prints the remaining travel time in hours and minutes
// Version: 1.1
// Owner: Andreas Manos
//-----------------------------------------------------------------------
// Log: 2020-11-05 Created the file, Andreas.
//-----------------------------------------------------------------------

#include <iostream>

using namespace std;

int main() 
{
    // Define and initialize variables
    char character;
    double distanceSe = 0;
    double speed = 0;
    do
    {
        system("CLS");                      /*clear the terminal*/

        // Read the values from user
        cout << "Give the distance in Swedish miles" << endl;
        cin >> distanceSe;
        cout << "Give the average speed" << endl;
        cin >> speed;

        // Calculate international distance, average speed in minutes and time in minutes
        double distanceInt = distanceSe * 10;
        double newSpeed = speed / 60;
        double time = (distanceInt / newSpeed) + 0.5;
        
        // Display time in hours and minutes
        cout << "===========================" << endl;
        cout << "the time is " << (int) time / 60 << " hours and " << (int) time % 60 << " minutes " << endl;
        cout << "===========================" << endl;

        cout << "\n\nDo you want to continue (Y/N)?";
        cin >> character;
    } while (!(character == 'N' || character == 'n'));

    return 0;
}