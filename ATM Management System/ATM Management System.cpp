#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

// Structure to hold account information
struct Account {
    string name;
    int pin;
    double balance;
};

// Sample database of accounts
unordered_map<int, Account> accounts = {
    {123456, {"Raja", 1111, 1000.0}},
    {654321, {"Lalit", 2222, 1500.0}},
    {789012, {"Rajesh", 3333, 2000.0}}
};

// Function prototypes
bool authenticate(int accNum, int pin);
void showMenu(int accNum);
void checkBalance(int accNum);
void deposit(int accNum);
void withdraw(int accNum);

int main() {
    int accNum, pin;
    cout << "===== Welcome to ATM =====" << endl;

    cout << "Enter Account Number: ";
    cin >> accNum;

    cout << "Enter PIN: ";
    cin >> pin;

    if (authenticate(accNum, pin)) {
        cout << "\nLogin Successful!" << endl;
        showMenu(accNum);
    } else {
        cout << "\nInvalid Account Number or PIN!" << endl;
    }

    cout << "\nThank you for using our ATM." << endl;
    return 0;
}

// Function to authenticate user
bool authenticate(int accNum, int pin) {
    return accounts.find(accNum) != accounts.end() && accounts[accNum].pin == pin;
}

// Display ATM menu
void showMenu(int accNum) {
    int choice;

    do {
        cout << "\n===== ATM Menu =====" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                checkBalance(accNum);
                break;
            case 2:
                deposit(accNum);
                break;
            case 3:
                withdraw(accNum);
                break;
            case 4:
                cout << "Logging out..." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 4);
}

// Check balance function
void checkBalance(int accNum) {
    cout << "Current Balance: rupees " << accounts[accNum].balance << endl;
}

// Deposit function
void deposit(int accNum) {
    double amount;
    cout << "Enter amount to deposit: rupees ";
    cin >> amount;

    if (amount > 0) {
        accounts[accNum].balance += amount;
        cout << "Deposited successfully." << endl;
    } else {
        cout << "Invalid amount." << endl;
    }
}

// Withdraw function
void withdraw(int accNum) {
    double amount;
    cout << "Enter amount to withdraw: rupees ";
    cin >> amount;

    if (amount > 0 && amount <= accounts[accNum].balance) {
        accounts[accNum].balance -= amount;
        cout << "Withdrawal successful." << endl;
    } else {
        cout << "Insufficient balance or invalid amount." << endl;
    }
}