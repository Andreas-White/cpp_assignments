//-----------------------------------------------------------------------
// File: PrimeNumbers.cpp
// Summary: Prints out the prime numbers between 1 and 100
// Version: 1.1
// Owner: Andreas Manos
//-----------------------------------------------------------------------
// Log: 2020-11-20 Created the file, Andreas.
//-----------------------------------------------------------------------

#include <iostream>

using namespace std;
bool isPrime(int num);

int main()
{
    system("CLS");

    // A for-loop to examine all the numbers up to 100
    for (int i = 2; i < 100; i++)
    {
        if (isPrime(i))
        {
            cout << i << " ";
        }
    }
}

// A function that examines if a number is prime and returns a boolean(true/false)
bool isPrime(int num)
{
    // If number is less than 2 return false
    if (num <= 1) {  
           return false;  
       }
       // Examines if the number is divisible by any number up to his half value
       for (int i = 2; i <= num / 2; i++) {  
           if (num % i == 0) {  
               return false;  
           }  
       }  
       // Returns true if none of the above is valid
       return true; 
}