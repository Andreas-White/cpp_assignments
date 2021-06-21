//-----------------------------------------------------------------------
// File: LogicalError.cpp
// Summary: Reads price and number of articles from user. Calculates and prints
// number, tax rate and price with tax rate (swedish "moms").
// Version: 1.1
// Owner: Andreas Manos
//-----------------------------------------------------------------------
// Log: 2005-03-09 Created the file, Mats!
// 2009-08-14 Revised by Tommy. Swedish variable names and output text.
// Number of items is now included.
// Code for the problem is placed in a separate function
// that is iterated in the main function.
// 2012-10-21 Revised by Anne. Converted to English version and VS 2012
// 2020-11-05 Revised by Andreas. Corrected logical errors as shown in the 
// comments in the code bellow
//-----------------------------------------------------------------------

// Preprocessor directives
#include <iostream>
#include <iomanip>

using namespace std;

// Prototypes
void priceCalculation();

int main()
{
    char answer;
    do
    {
        system("CLS");                      /*Not an error, but it looks more organised in terminal*/
        priceCalculation();
        cout << "One more time? (Y/N): ";
        cin >> answer;
    } while (answer == 'Y' || answer == 'y');   /*was missing an equal (=) sign so the statement was always 
                                                  when there was an input*/
    return 0;
}

//-----------------------------------------------------------------
// void priceCalculation()
//
// Summary: Reads price and number of articles from user. Calculates and prints
// quantity, vat and price with vat
// Returns: -
//-----------------------------------------------------------------
void priceCalculation()
{
    // Define and initialize constants and variables
    const int RATE = 25; // tax rate in percent
    double price = 0; // price per piece
    int nrOfArticles = 0; // number of articles
    double rateSEK = 0; // tax rate in SEK
    double totalPrice = 0; // price incl. tax rate
    const double decimalRate = (double) RATE / 100;  /*I include this one to have the tax in decimal form
                                                       and cast it to double*/

    // Read price and number of articles
    cout << "Enter the price excl. the tax rate (swedish moms): ";
    cin >> price;
    cout << "Enter the number of articles: ";
    cin >> nrOfArticles;

    // Calculate total price and tax rate
    cout << decimalRate << "rate" << endl;
    rateSEK = (price * nrOfArticles) * decimalRate;  /*I replaced totalPrice with the multiplication of price 
                                                       and nrOfArticles and multiplied with the decimalRate*/
    totalPrice = (nrOfArticles * price) + rateSEK;   /*I reaplaced the 1+Rate with rateSEK since we need the
                                                       total tax amount of the products*/

    // Display result with 2 decimals
    cout << fixed << showpoint << setprecision(2);
    cout << nrOfArticles << " number of articles cost " << totalPrice << " kr. "
    << endl << "Of this " << rateSEK << " kr is the tax rate." << endl;
}
