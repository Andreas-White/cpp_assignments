//-----------------------------------------------------------------------
// File: TimeStructures.cpp
// Summary: A program that uses four funtions the first for calculating 
// total minutes, the second for printing time format, the third for 
// finding the difference between two times and the fourth for finding
// the maximum difference between 200 different times
// Version: 1.1
// Owner: Andreas Manos
//-----------------------------------------------------------------------
// Log: 2020-12-27 Created the file, Andreas.
//-----------------------------------------------------------------------

#include <iostream>
#include <ctime>

using namespace std;

struct TimeType
{
    int hour;
    int min;
};

// Prototypes
int toMinutes(TimeType t);
TimeType toTime(int x);
TimeType timeDifference(TimeType a, TimeType b);
TimeType dynamicTimes();

int main()
{
    int minutes;
    TimeType timeA = {10, 15};
    minutes = toMinutes(timeA);
    cout << minutes << " minutes" << endl;

    minutes = 124;
    TimeType time = toTime(minutes);
    if (time.min < 10)
    {
        cout << time.hour << ":0" << time.min << endl;
    }else
    {
        cout << time.hour << ":" << time.min << endl;
    }

    TimeType timeB = {10, 30}, timeC = {13, 20}, difference;
    difference = timeDifference(timeB, timeC);
    if (difference.min < 10)
    {
        cout << difference.hour << ":0" << difference.min << endl;
    }else
    {
        cout << difference.hour << ":" << difference.min << endl;
    }
    
    TimeType maxDiff = dynamicTimes();
    cout << maxDiff.hour << ":" << maxDiff.min;
    return 0;
}

// Calculates the total number of minutes of a struct Timetype
int toMinutes(TimeType t)
{
    return (t.hour * 60) + t.min;
}

// Returns a Timetype after inputing the total minutes as an integer
TimeType toTime(int x)
{
    TimeType tm;
    tm.hour = x / 60;
    tm.min = x % 60;
    return tm;
}

// Calculates the differne of two Timetypes and returns it as a new Timetype
TimeType timeDifference(TimeType a, TimeType b)
{
    int dif = 0;
    if (toMinutes(a) >= toMinutes(b))
    {
        dif = toMinutes(a) - toMinutes(b);
    }else
    {
        dif = toMinutes(b) - toMinutes(a);
    }
    
    return toTime(dif);
}

// Creates a dynamic array of 200 diferent Timetypes and returns the max diffence between them as a new Timetype
TimeType dynamicTimes()
{
    // Create dynamic array of Timetype type
    TimeType *times = new TimeType[200];
    // Initialise the seed for generating random values
    srand(time(0));

    // Create 200 random Timetypes values for the dynamic array
    for (int i = 0; i < 200; i++)
    {
        times[i].hour = rand() % 100; // so it doesn't assign to large values
        times[i].min = rand() % 60; // the range for a minute
    }
    
    // Calculating the max differnce between the Timetypes in the times array
    int max = 0;
    for (int i = 0; i < 200; i++)
    {
        for (int j = i; j < 200; j++)
        {
            if (toMinutes(timeDifference(times[i],times[j])) > max)
            {
                max = toMinutes(timeDifference(times[i],times[j]));
            }
            
        }
        
    }
    // Returning the max difference as a new Timetype
    return toTime(max);
}