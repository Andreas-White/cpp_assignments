#include <iostream>

using namespace std;

enum week { Monday = 17, Tuesday, Wednesday, Thursday, Friday,
Saturday  = -12, Sunday };

int main()
{
    week today = Monday;
    week tomorrow = Tuesday;
    week lord = Sunday;
    cout << today << "  " << tomorrow << "  " << lord; 
    return 0;
}