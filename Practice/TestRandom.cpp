#include <ctime>
#include <iostream>

using namespace std;

void printRandom();

int main()
{
    srand(time(0));

    printRandom();
    
    return 0;
}

void printRandom()
{
    for (int i = 0; i < 10; i++)
    {
        int x = (rand() % 5) + 1;
        cout << "Attempt " << i << ": " << x << endl;
    }
}