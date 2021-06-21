//-----------------------------------------------------------------------
// File: DiceThronesGame.cpp
// Summary: A game of dices between a user and the computer. Whoever, reaches
// at 100 points first wins!
// Version: 1.1
// Owner: Andreas Manos
//-----------------------------------------------------------------------
// Log: 2020-11-28 Created the file, Andreas.
//-----------------------------------------------------------------------

#include <iostream>

using namespace std;

// Prototypes
int humanTurn(int humanTotalScore);
int computerTurn(int computerTotalScore);

int main()
{
    // Define and initialize variable
    int humanTotalScore = 0;
    int computerTotalScore = 0;
    char choice;

    system("CLS");
    cout << "Welcome to the Game of Dice Thrones!" << endl;

    // The main do-while loop that iterates through user's and computer's turns each time and
    // checks who reaches first at 100 points
    do
    {
        // Calling the function humanTurn() and uptading humanTotalScore
        humanTotalScore += humanTurn(humanTotalScore);

        cout << "It's the computer's turn!" << endl;

        // Calling the function computerTurn() and uptading computerTotalScore
        computerTotalScore += computerTurn(computerTotalScore);

        cout << "The computer loses its your turn. Enter 'c' to continue. " << endl;
        cin >> choice;
            
    } while (humanTotalScore < 100 && computerTotalScore < 100 && toupper(choice) == 'C');
    
    system("CLS");
    // Printing out the scores of user and computer (wasn't required, but provides better 
    // game experience)
    cout << "your score is: " << humanTotalScore << endl;
    cout << "computer's score is: " << computerTotalScore << endl;

    // Printing out the game result according to the final scores
    if (humanTotalScore > computerTotalScore)
    {
        cout << "You Won! :)";
    }
    else if (humanTotalScore < computerTotalScore)
    {
        cout << "You Lost! :(";
    }else
    {
        cout << "It's a tie! :/";
    }
    return 0;
}

// A function that manages each turn of the user and return its value as an integer 
int humanTurn(int humanTotalScore)
{
    // Define and initialize variable
    int turnH = 0;
    int rollH = 0;
    char choice;

    cout << "It's your turn! Enter 'r' to roll." << endl;
    cin >> choice;

    // The if-statement is responsible for the first roll and updating the turn value of each human
    // turn
    if (toupper(choice) == 'R')
    {
        rollH = 1 + rand() % 6;
        cout << "You rolled " << rollH << endl;
        if (rollH != 1)
        {
            turnH += rollH;
            cout << "Your score this round is: " << turnH << endl;
        }
        else
        {
            turnH = 0;
        }       
    }

    // The while-loop is responsible for checking each action of the human (either roll or hold) after
    // the first roll successfully completed and updating the turn value
    while (toupper(choice) == 'R' && rollH != 1)
    {
        cout << "If you hold, your total score would be: " << turnH << endl;
        cout << "Press 'h' to hold or 'r' to roll again." << endl;
        cin >> choice;

        if (toupper(choice) == 'H')
        {
            break;
        }  

        rollH = 1 + rand() % 6;
        cout << "You rolled " << rollH << endl;
        if (rollH != 1)
        {
            turnH += rollH;
            cout << "Your score this round is: " << turnH << endl;
        }else
        {
            turnH = 0;
            break;
        } 
    } 

    return turnH;
}

// A function that manages each turn of the computer and return its value as an integer 
int computerTurn(int computerTotalScore)
{
    // Define and initialize variable
    int turnC = 0;
    int rollC = 0;
    char choice;
    
    // The while-loop is responsible for checking each action of the compueter (either roll or max turn 
    // value) and updating the turn value
    while (rollC != 1 && turnC <= 10)
    {
        rollC = 1 + rand() % 6;
        if (rollC != 1)
        {
            cout << "The computer rolled " << rollC << endl;
            turnC += rollC;
        }
        else
        {
            cout << "The computer rolled 1" << endl;
            turnC = 0;
        }           
    }
    return turnC; 
}