//-----------------------------------------------------------------------
// File: Issue.cpp
// Summary: A program that imitates the tossing of a coin
// Version: 1.1
// Owner: Andreas Manos
//-----------------------------------------------------------------------
// Log: 2020-12-26 Created the file, Andreas.
//-----------------------------------------------------------------------

#include <iostream>
#include <ctime>

using namespace std;

enum Coin {Tails, Heads};

int main()
{
    int frequency0 = 0, frequency1 = 0;
    Coin face;
    
    /*I just moved the srand function outside the for loop, since the srand is using the system clock as seed
    and if we call it inside the loop, which is completed in less than a second, it will produce the same 
    random number*/
    srand(time(0));

    for (int counter = 1; counter <= 10; ++counter)
    {
        
        face = Coin(rand()% 2);
        switch (face)
        {
            case Tails: ++frequency0;
                        break;
            case Heads: ++frequency1;
                        break;
        }
    }

    cout << "Tails were rolled " << frequency0 << " times" << endl;
    cout << "Heads were rolled " << frequency1 << " times" << endl;

    cin.get();
    
    return 0;
}