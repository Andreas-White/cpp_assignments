#include <iostream>

using namespace std;

union Test
{
    int x;
    char c;
    bool b;
};


int main()
{
    system("CLS");
    int a = 10;
    int intArr[10];
    char charArr[10];
    Test t;
    t.x = 1;
    //t.c = 'B';
    cout << t.c << "  " << t.x << "  " << t.b << endl;
    (t.b)? cout << "True" << t.c << endl : cout << "False" << t.x << endl;

    cout << "short: " << sizeof (short) << endl;
    cout << "integer: " << sizeof (int) << endl;
    cout << "long: " << sizeof (long) << endl;
    cout << "long long: " << sizeof (long long) << endl;
    cout << "char: " << sizeof (char) << endl;
    cout << "float: " << sizeof (float) << endl;
    cout << "double: " << sizeof (double) << endl;
    cout << "bool: " << sizeof (bool) << endl;
    cout << "void: " << sizeof (void) << endl;
    cout << "union: " << sizeof (Test) << endl;

    cout << "size of int type variable: " << sizeof a << endl;
    cout << "size of a numeric expression: " << sizeof (5+10) << endl;
    cout << "size of an int Array of 10 elements: " << sizeof intArr << endl;
    cout << "size of char Array to store 10 elements: " << sizeof charArr << endl;

    return 0;
}