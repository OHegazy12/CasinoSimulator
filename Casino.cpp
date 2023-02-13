//
// Created by Omar Hegazy on 2/12/23.
//

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

void rules();

void rules()
{
    cout << "======CASINO NUMBER GUESSING RULES======" << endl;
    cout << "Rule 1: You must choose a number between 1 & 10." << endl;
    cout << "Rule 2: Winner gets the money he/she/it betted back 10-fold." << endl;
    cout << "Rule 3: If you guess wrong, you lose the amount you bet." << endl;
    cout << "Rule 4: Eat the grip." << endl;
}

int main()
{
    string playerName;
    int bettingAmount;
    int balance; // How much the player has
    int dice; // Determines the random number
    int guess;
    char choice;

    srand(time(0)); // Random generator

    cout << "========== WELCOME TO CASINO WORLD ==========" << endl;

    cout << "Enter name: " << endl;
    cin >> playerName;

    cout << "Enter the amount you want to have as your starting balance: " << endl;
    cin >> balance;
    do
    {
        rules(); // Displays the game rules

        cout << "You're current balance is now " << balance << " dollars." << endl;
        do
        {
            cout << "Enter amount to bet: ";
            cin >> bettingAmount;

            cout << playerName << " chooses to bet " << bettingAmount << " dollars." << endl;

            if (bettingAmount > balance)
            {
                cout << "Insufficient balance needed to bet said amount. Please try again. " << endl;
            }
        } while (bettingAmount > balance);
        do
        {
            cout << "Guess a number between 1 and 10." << endl;
            cin >> guess;

            if (guess <= 0 || guess > 10)
            {
                cerr << "Number needs to be between 1 and 100. Please try again." << endl;
            }
        } while (guess <= 0 || guess > 10);

        dice = rand() % 10 + 1; // When run, the dice generates a random number modulo 10 plus 1.
        if (dice == guess)
        {
            int winnings = bettingAmount * 10; // Represents how much the player wins
            cout << "Correct! You have won " << winnings << " dollars!" << endl;
            balance += winnings;
        }
        else
        {
            cout << "That's tuff. The winning number was " << dice << "." << " You have lost " << bettingAmount << " dollars. Get wrecked :)" << endl;
            balance -= bettingAmount ;
        }

        cout << "You now have a balance of " << balance << " dollars." << endl;
        if(balance == 0)
        {
            cout << "You are officially a brokie. Come back when you have Top G dollars on you." << endl;
            break;
        }

        cout << "Would you like to play again? " << endl;
        cin >> choice;
    }
    while (choice == 'Y' || choice == 'y');

    cout << "Big ups for playing Casino World! Your end balance is " << balance << " dollars!" << endl;
    return 0;
}

