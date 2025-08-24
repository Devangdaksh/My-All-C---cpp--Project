#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

string getComputerChoice() {
    int choice = rand() % 3; // 0, 1, or 2
    switch(choice) {
        case 0: return "rock";
        case 1: return "paper";
        case 2: return "scissors";
    }
    return "rock"; // Default (should never reach here)
}

string getResult(string user, string computer) {
    if(user == computer) return "It's a tie!";
    if((user == "rock" && computer == "scissors") ||
       (user == "paper" && computer == "rock") ||
       (user == "scissors" && computer == "paper"))
        return "You win!";
    return "You lose!";
}

int main() {
    srand(time(0)); // Seed for random number generator
    string userChoice, computerChoice;
    char playAgain;

    cout << "Rock, Paper, Scissors Game (C++)\n\n";

    do {
        cout << "Enter your choice (rock, paper, scissors): ";
        cin >> userChoice;
        // Convert input to lowercase for consistency
        for (auto &c : userChoice) c = tolower(c);

        // Validate input
        if(userChoice != "rock" && userChoice != "paper" && userChoice != "scissors") {
            cout << "Invalid input, try again.\n";
            continue;
        }

        computerChoice = getComputerChoice();
        cout << "Computer chose: " << computerChoice << endl;
        cout << getResult(userChoice, computerChoice) << endl;

        cout << "Play again? (y/n): ";
        cin >> playAgain;
    } while(playAgain == 'y' || playAgain == 'Y');

    cout << "Thank you for playing!\n";
    return 0;
}
