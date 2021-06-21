//-----------------------------------------------------------------------
// File: SPSGAme.cpp
// Summary: A program that imitates the stone-paper-scissors game
// Version: 1.1
// Owner: Andreas Manos
//-----------------------------------------------------------------------
// Log: 2020-12-28 Created the file, Andreas.
//-----------------------------------------------------------------------

#include <iostream>
#include <ctime>

using namespace std;

// Enumerations
enum choice {stone, paper, scissors};

int main()
{
    system("CLS");
    // Define variables
    int humanChoice;
    int compChoice;
    char answer;

    cout << "STONE SCISSORS PAPER" << endl;
    cout << "=====================" << endl;

    // The seed for the random generated numbers
    srand(time(0));
    
    do
    {
        // Define more variables
        int humanScore = 0;
        int compScore = 0;

        do
        {
            // Prompt user for input
            cout << "Your choice (Stone=0/Scissors=1/Paper=2): ";
            cin >> humanChoice;

            // Connecting the user's input to enumerations
            choice human;
            switch (humanChoice)
            {
            case 0:
                human = stone;
                break;
        
            case 1:
                human = scissors;
                break;
            case 2:
                human = paper;
                break;
            default:
                cout << "Wrong input!";
            }

            // Generating random number for computer's choice
            compChoice = rand() % 3;

            // Connecting the computer's choice to enumerations
            choice comp;
            switch (compChoice)
            {
            case 0:
                comp = stone;
                cout << "Computer choose Stone" << endl;
                break;
        
            case 1:
                comp = scissors;
                cout << "Computer choose Scissors" << endl;
                break;
            case 2:
                comp = paper;
                cout << "Computer choose Paper" << endl;
                break;
            default:
                cout << "Wrong input!";
            }

            // All the possible outcomes
            if (human == stone && comp == scissors)
            {
                cout << "You won!" << endl;
                humanScore++;
            }else if (human == scissors && comp == paper)
            {
                cout << "You won!" << endl;
                humanScore++;
            }else if (human == paper && comp == stone)
            {
                cout << "You won!" << endl;
                humanScore++;
            }else if(comp == stone && human == scissors)
            {
                cout << "Computer won!" << endl;
                compScore++;
            }else if (comp == scissors && human == paper)
            {
                cout << "Computer won!" << endl;
                compScore++;
            }else if (comp == paper && human == stone)
            {
                cout << "Computer won!" << endl;
                compScore++;
            }else if(comp == stone && human == stone)
            {
                cout << "Equal!" << endl;
            }else if (comp == scissors && human == scissors)
            {
                cout << "Equal!" << endl;
            }else if (comp == paper && human == paper)
            {
                cout << "Equal!" << endl;
            }

            // Presenting the score
            cout << "Score (you - computer): " << humanScore << " - " << compScore << endl;

        } while (humanScore < 10 && compScore < 10);

        // Presenting the final score
        if (humanScore > compScore)
        {
            cout << "You won with " << humanScore << " - " << compScore << endl;
        }else
        {
            cout << "You lost with " << humanScore << " - " << compScore << endl;
        }
        
        cout << "One more time (Y/N) ";
        cin >> answer;
    } while (toupper(answer) == 'Y');
    
    return 0;
}