#include <iostream>

using namespace std;

int main()
{
    char choice;
    int years;
    int inv;
    double total = 0;
    do
    {
        system("CLS");
        cout << "Provide years of investment: ";
        cin >> years;

        cout << "\nProvide amount of monthly investement: ";
        cin >> inv;

        int period = 12 * years;

        for (int i = 0; i < period; i++)
        {
            total += inv;
            if (i % 11 == 0)
            {
                total = total + (total * 0.1336);
            }
        }

        cout << "The total amount of money in the end is: " << total << endl;
        
        cout << "Want to retry? (Y/N): ";
        cin >> choice;
    } while (toupper(choice) == 'Y');
    
    return 0;
}