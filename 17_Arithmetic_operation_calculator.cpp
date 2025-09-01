/*
 ====================================================================
  Arithmetic Operations Calculator
 --------------------------------------------------------------------
  Description:
    This program allows the user to perform basic arithmetic 
    operations (Addition, Subtraction, Multiplication, Division) 
    on two numbers. It includes input validation for numeric input 
    and menu selection, and displays which of the two numbers is 
    greater or if they are equal.

    After each operation, the user is prompted to perform another 
    calculation or exit.

  Features:
    - Performs four basic arithmetic operations
    - Validates user input for both numbers and menu selection
    - Displays greater/smaller of the two numbers
    - Allows repeated calculations until the user quits

  Author: CS Section 1, Group 5
  Date  : June 6, 2025
 ====================================================================
*/

#include <iostream>          // For input/output operations
#include <string>            // For using string data type
#include <sstream>           // For parsing user input safely
#include <cctype>            // For tolower function
using namespace std;


// Function Prototypes
void displayResult(double num1, double num2, int choice);  // Handles calculation and comparison


// Main program starts here
int main() {
    double num1, num2;        // Variables to store two numbers
    int choice;               // Variable for menu selection
    string input;             // Input string for safe parsing
    char again;               // Variable to control repetition

    // Welcome message
    cout << "============================================================\n";
    cout << "       Welcome to the Basic Arithmetic Calculator           \n";
    cout << " This program performs basic math operations on two numbers\n";
    cout << "============================================================\n\n";

    do {
        // Prompt for first number with validation
        do {
            cout << "Enter the first number: ";
            getline(cin, input);
            stringstream ss(input);
            if (!(ss >> num1) || (ss >> ws && !ss.eof())) {
                cout << "Invalid input. Please enter a valid number.\n";
            } else {
                break;
            }
        } while (true);

        // Prompt for second number with validation
        do {
            cout << "Enter the second number: ";
            getline(cin, input);
            stringstream ss(input);
            if (!(ss >> num2) || (ss >> ws && !ss.eof())) {
                cout << "Invalid input. Please enter a valid number.\n";
            } else {
                break;
            }
        } while (true);

        // Display operation menu and validate selection
        do {
            cout << "\nPlease select an operation:\n";
            cout << "1) Addition\n";
            cout << "2) Subtraction\n";
            cout << "3) Multiplication\n";
            cout << "4) Division\n";
            cout << "Enter your choice (1-4): ";

            getline(cin, input);
            stringstream ss(input);
            if (!(ss >> choice) || (ss >> ws && !ss.eof()) || choice < 1 || choice > 4) {
                cout << "Invalid selection. Please choose a number between 1 and 4.\n";
                choice = 0;
            } else {
                break;
            }
        } while (true);

        // Perform operation and display result
        displayResult(num1, num2, choice);

        // Prompt to repeat
        do {
            cout << "\nDo you want to perform another calculation? (y/n): ";
            getline(cin, input);
            if (!input.empty()) {
                again = tolower(input[0]);
            } else {
                again = 'n'; // Default to 'n' on empty input
            }

            if (again != 'y' && again != 'n') {
                cout << "Invalid input. Please enter 'y' or 'n'.\n";
            }
        } while (again != 'y' && again != 'n');

    } while (again == 'y');

    // Exit message
    cout << "\nThank you for using the calculator. Goodbye!\n";
    return 0;
}


/* ============================================================================
 Function  : displayResult
 Purpose   : Performs the selected arithmetic operation and compares numbers
 Parameters: 
     - double num1: First number
     - double num2: Second number
     - int choice : Menu selection for operation
============================================================================= */
void displayResult(double num1, double num2, int choice) {
    cout << "\nResult: ";
    switch (choice) {
        case 1:
            cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
            break;
        case 2:
            cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
            break;
        case 3:
            cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
            break;
        case 4:
            if (num2 != 0) {
                cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
            } else {
                cout << "Error: Division by zero is not allowed.\n";
                return;
            }
            break;
    }

    // Display which number is greater
    if (num1 > num2) {
        cout << num1 << " is greater than " << num2 << endl;
    } else if (num2 > num1) {
        cout << num2 << " is greater than " << num1 << endl;
    } else {
        cout << "Both numbers are equal.\n";
    }
}
