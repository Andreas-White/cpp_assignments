//-----------------------------------------------------------------------
// File: WindTemperature.cpp
// Summary: Reads two user's inputs the air temperature and the wind's 
// speed and after it calculates the perceived temperature it prints the
// result
// Version: 1.1
// Owner: Andreas Manos
//-----------------------------------------------------------------------
// Log: 2020-11-06 Created the file, Andreas.
//-----------------------------------------------------------------------

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // Define and initialize variables 
    int windTemp = 0;
    int windSpeed = 0;
    char character;

    do
    {
        system("CLS");
        // Request user inputs of air temperature and speed of the wind
        cout << "Give the air temperature in Celsius: " << endl;
        cin >> windTemp;
        cout << "Give the wind's speed in m/s: " << endl;
        cin >> windSpeed;

        //Calculate the perceived temperature
        double percTemp =  13.126667 + 0.6215 * windTemp - 13.924748 * pow(windSpeed,0.16) 
                        + 0.4875195 * windTemp * pow(windSpeed,0.16) - 0.5;  // I subtract 0.5 in order to 
                                                                             //round to the previous integer

        // Display the result
        cout << "==========================================================" << endl;
        cout << "For temperature at " << windTemp << "\370C and speed at " << windSpeed << "m/s, the perceived"
             << "temperature is: " << (int) percTemp <<"\370C" << endl;
        cout << "==========================================================" << endl;

        cout << "Do you want to rerun (Y/N)? " << endl;
        cin >> character;

    } while (character == 'Y' || character == 'y');
    
    return 0;
}