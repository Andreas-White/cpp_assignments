//-----------------------------------------------------------------------
// File: Dates.cpp
// Summary: A program that takes as input a date of the form YYYYMMDD as 
// an integer and prints out the date of the next day in the same format
// Version: 1.1
// Owner: Andreas Manos
//-----------------------------------------------------------------------
// Log: 2020-11-26 Created the file, Andreas.
//-----------------------------------------------------------------------

#include <iostream>

using namespace std;

// Prototypes
bool leapYear(int year);
int daysInMonth(int year, int month);
void tomorrow(int date);

int main()
{
    system("CLS");
    // Define variables
    int date;
    char ans;

    do
    {
        // Prompt the user for input
        cout << "Enter a date on the form YYYYMMDD: ";
        cin >> date;
        cout << "Tomorrow it is: ";
        tomorrow(date);

        // Asking the user if he/she wants to rerun it (wasn't required, but feels better)
        cout << "\nDo you want to retry(Y/N): ";
        cin >> ans;
    } while (toupper(ans) == 'Y');
    
    return 0;
}

// a function that a year as an integer and checks if it's a leap year
bool leapYear(int year)
{
    if (((year % 4 == 0) && (year % 100!= 0)) || (year%400 == 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

// a function that reads to integers representing a year and a month and calculates the number of days 
// of that month
int daysInMonth(int year, int month)
{
    if (leapYear(year) && month == 2)
    {
        return 29;
    }
    else if (!leapYear(year) && month == 2)
    {
        return 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        return 30;
    }
    else
    {
        return 31;
    }
}

// reads a date as an integer and prints out the date of the next day
void tomorrow(int date)
{
    int days = date % 100;
    int months = (date % 10000) / 100;
    int year = date / 10000;

    // I used multiple if statements for each case
    if (daysInMonth(year,months) == days && months == 12)
    {
        cout << year + 1 << "0101";
    }
    else if (daysInMonth(year,months) == days && months == 11)
    {
        cout << year << "1201";
    }
    else if (daysInMonth(year,months) == days && months == 10)
    {
        cout << year << "1101";
    }
    else if (daysInMonth(year,months) == days && months == 9)
    {
        cout << year << "1001";
    }
    else if (daysInMonth(year,months) == days && months < 9)
    {
        cout << year << "0" << months + 1 << "01";
    }
    else
    {
        cout << date + 1;
    }    
}