//-----------------------------------------------------------------------
// File: CompileError.cpp
// Summary: This program calculates the weekly pay, given hours per week
// and wages per hour.
// Version: 1.1
// Owner: Andreas Manos
//---------------------------------------------------------------------
// Log: 2005-03-09 Created the file, Mats!
// 2009-08-14 Revised by Tommy.Using manipulators to format output
// instead of IO-flags. Inserted "wait for return code" at the end.
// 2012-10-21: Revised by Anne. Converted to English version and VS2012
// 2020-11-05 Revised by Andreas. Corrected syntactical errors as shown
// in the comments below
//-----------------------------------------------------------------------

#include <iostream> // Preprocessor directives
#include <iomanip>

using namespace std;

int main()   /*main() should be declared int, since we are returning int in the end 
               or delete return statement*/
{
     system("CLS");                      /*Not an error, but it looks more organised in terminal*/
     
     // Define and initialize variables
     int hoursPerWeek = 35;
     double hourlyWages = 83;

     // Calculate weekly salary
     double weeklyWages = hoursPerWeek * hourlyWages; /*weeklyWages should have identifier*/

     // Display results
     cout << fixed // Floating point format
          << setprecision(2) // 2 decimals
          << showpoint; // Show trailing zero’es
     cout << " Given an hourly wage of " << hourlyWages << " kr" << endl
          << " and the number of hours per week " << hoursPerWeek << endl
          << " the weekly wages will be: " << weeklyWages << " kr" << endl; /*at the end of the line should be 
                                                                              a semicolon ";"*/
     cout << "\nPress return!";

     cin.get(); // Wait for return

     return 0;
}