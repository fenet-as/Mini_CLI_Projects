/*
 ====================================================================
  Automatic Teller Machine (ATM) Program
 --------------------------------------------------------------------
  Description:
    This program simulates a simple ATM that manages a user's account
    balance. It allows the user to withdraw and deposit amounts with
    input validation and displays the updated balance after each 
    transaction. The user can continue to perform transactions until 
    they choose to exit.

  Features:
    - Validates numeric inputs for balance, withdrawal, and deposit
    - Prevents withdrawal of amount exceeding balance
    - Prevents zero or negative withdrawals/deposits
    - Displays updated balance after each transaction

  Author: [CS section 1, group 5]
  Date: [June 10, 2025]
 ====================================================================
*/

#include <iostream>                     // Required for input/output
#include <limits>                       // For input validation
#include <cctype>                       // For character handling (tolower)
using namespace std;                    // Use standard namespace

// Function Prototypes
int getValidatedAmount(const string& prompt);    // Validates and returns a positive integer amount
char getMenuChoice();                            // Gets and validates menu option choice

// Main program starts here
int main() {
    int balance;                                // User's account balance
    int amount;                                 // Amount to withdraw or deposit
    char choice;                                // Menu choice

    // Welcome message
    cout << "==================================================\n";
    cout << "           Welcome to the Automatic Teller Machine (ATM)         \n";
    cout << " This program allows you to withdraw and deposit amounts\n";
    cout << " from your account and displays your updated balance.\n";
    cout << "==================================================\n\n";

    // Get initial balance from user
    balance = getValidatedAmount("Enter your initial account balance: ");

    // Warn if balance is zero
    if (balance == 0) {
        cout << "\nYou currently have no funds in your account.\n";
    }

    // Main menu loop
    do {
        cout << "\n--------------------------------------------------\n";
        cout << "Select an option:\n";
        cout << "1. Withdraw Amount\n";
        cout << "2. Deposit Amount\n";
        cout << "3. Exit\n";
        cout << "--------------------------------------------------\n";

        choice = getMenuChoice();

        switch (choice) {
            case '1':   // Withdraw
                while (true) {
                    amount = getValidatedAmount("Enter amount to withdraw: ");
                    if (amount > balance) {
                        cout << "Insufficient balance. Try a smaller amount.\n";
                    } else {
                        balance -= amount;
                        cout << "Withdrawal successful.\n";
                        cout << "New balance: " << balance << endl;
                        break;
                    }
                }
                break;

            case '2':   // Deposit
                amount = getValidatedAmount("Enter amount to deposit: ");
                balance += amount;
                cout << "Deposit successful.\n";
                cout << "New balance: " << balance << endl;
                break;

            case '3':   // Exit
                cout << "\nThank you for using the ATM program. Goodbye!\n";
                break;
        }
    } while (choice != '3');

    return 0;
}

/* ====================================================================
 Function  : getValidatedAmount
 Purpose   : Prompt user for a positive whole number input and validate it
 Parameters: const string& prompt - prompt message to display
 Returns   : int - validated positive integer amount
 ==================================================================== */
int getValidatedAmount(const string& prompt) {
    int value;

    while (true) {
        cout << prompt;
        if (!(cin >> value) || value <= 0) {
            cout << "Invalid input. Please enter a positive whole number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
            return value;
        }
    }
}

/* ====================================================================
 Function  : getMenuChoice
 Purpose   : Display menu and get valid choice input from user ('1', '2', or '3')
 Returns   : char - valid menu option
 ==================================================================== */
char getMenuChoice() {
    char ch;

    while (true) {
        cout << "Enter your choice (1-3): ";
        cin >> ch;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

        if (ch == '1' || ch == '2' || ch == '3') {
            return ch;
        } else {
            cout << "Invalid choice. Please enter 1, 2, or 3.\n";
        }
    }
}
