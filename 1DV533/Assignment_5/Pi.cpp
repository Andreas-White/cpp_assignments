//-----------------------------------------------------------------------
// File: Pi.cpp
// Summary: A program that determines the values of Pi by generating 
// random coordinates on the surface of square that encloses a quarter-
// cicle. 
// Version: 1.1
// Owner: Andreas Manos
//-----------------------------------------------------------------------
// Log: 2020-12-30 Created the file, Andreas.
//-----------------------------------------------------------------------

#include <iostream>
#include <ctime>
#include <cmath>
#include <iomanip>

using namespace std;

const double R = 100; // Radius of the circle (=square side) is determined here

struct Coord // Data representation of a point where the arrow hits
{
    double x, y;
};

// Prototypes
Coord throwArrow();
bool below(Coord c);
void throwSeries(int n);

int main()
{
    system("CLS");
    srand(time(0));

    // Printing the headers
    cout << setw(15) << "n" << setw(15) << "pi" << setw(15) << "Rel. fault" << endl;
    cout << setw(15) << setfill('-') << "|"<< setw(15) << setfill('-') << "|";
    cout << "--------------" << endl;

    int n = 0;
    // Printing the values of Pi and the relevant faults according to the requirements
    for (int i = 0; i < 100; i++)
    {
        n += 100;
        throwSeries(n);
    }
    
    return 0;
}

// Creates a Coord type with random values
Coord throwArrow()
{
    Coord c;
    c.x = (rand() % (int) R) + 1;
    c.y = (rand() % (int) R) + 1;
    return c;
}

// Examines if the Coord is inside circle arc
bool below(Coord c)
{
    if (pow(c.x,2) + pow(c.y,2) < pow(R,2))
    {
        return true;
    }else
    {
        return false;
    }
}

// Prints the values of Pi and relevant Fault n times
void throwSeries(int n)
{
    // Define and initialise the variables
    double pi = 0;
    double relFel = 0;
    double numCicle = 0;
    Coord c[n];

    int count = 0;
    // Calculate the number of arrows that land inside the cicle arc
    for (int i = 0; i < n; i++)
    {
        c[i] = throwArrow();
        if (below(c[i]))
        {
            numCicle++;
        }
    }
    // Calculate pi
    pi = 4 * (numCicle / (double) n);
    // Calculate relevant fault
    relFel = ((pi - M_PI) / M_PI) * 100;

    // Printing the values accordingly
    cout << setw(15) << setfill(' ') << n;
    cout << fixed << setprecision(5);
    cout<< setw(15)<< setfill(' ')  << pi << setw(15)<< setfill(' ') ;

    cout << fixed << setprecision(1);
    cout << relFel << endl;
}