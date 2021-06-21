//-----------------------------------------------------------------------
// File: PowerFunction.cpp
// Summary: Reads one or two integers and prints the square power if there 
// is one integer and the first to the power of the second if there are
// two integers
// Version: 1.1
// Owner: Andreas Manos
//-----------------------------------------------------------------------
// Log: 2020-11-24 Created the file, Andreas.
//-----------------------------------------------------------------------

#include <iostream>

using namespace std;

// Write the function declaration (prototype) for power here...
int power(int x, int y = 2);

int main()
{
 for (int i = 0; i < 10; i++)
 cout << power(2, i) << " "; // prints 2 raised to the power of i

 cout << endl;
 cout << power(3) << endl; // will print 9
 cout << power(4) << endl; // will print 16
 cout << power(5) << endl; // will print 25
 return 0;
}

// Write the function definition for power here...
int power(int x, int y)
{
    // case if the x is even, using bitwise left shift operator to double the value of x
    if (x % 2 == 0)
    {
        return x << y;
    }
    // case if x is odd, just multiplying with itself
    else
    {
        return x * x;
    }    
}