/*
 ====================================================================
  Basic Arithmetic Calculator Program
 --------------------------------------------------------------------
  Description:
    This program performs basic arithmetic operations (+, -, *, /) 
    using two numbers entered by the user. It uses separate functions 
    for multiplication and division. The program validates user input, 
    handles division by zero, and repeats the process based on the 
    user's choice.

  Features:
    - Supports addition, subtraction, multiplication, and division
    - Validates input and prevents division by zero
    - Uses a loop to allow repeated calculations
    - functions for multiplication and division
    - Graceful handling of invalid operators

  Author: [CS section 1, group 5 members]
  Date: [June 6, 2025]
 ====================================================================
*/

#include <iostream>                     // Required for input/output
#include <limits>                       // For input validation
#include <cctype>                       // For tolower()
using namespace std;                    // Use standard namespace

// Constant Definitions
const double ERROR_DIV_ZERO = 0.0;      // Value returned when division by zero occurs

// Function Prototypes
void product(double a, double b);             // Prints the product of two numbers
void quotient(double a, double b);       // prints the quotient of two numbers

// ============================================================================
// Main Program
// ============================================================================
int main() {
    double num1, num2;                     // Numbers to be input by the user
    char op;                            // Operator
    char choice;                        // User's choice to repeat

    // Welcome message
    cout << "====================================================\n";
    cout << "       Welcome to the Basic Calculator Program       \n";
    cout << "   Perform operations (+, -, *, /) on two numbers.   \n";
    cout << "   Enter 'n' or 'N' to quit after each calculation.  \n";
    cout << "====================================================\n\n";

    // Loop to repeat calculations
    do {
        // Input: First number
        cout << "Enter first number: ";
        while (!(cin >> num1)) {
            cout << "Invalid input. Please enter a valid integer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Input: Second number
        cout << "Enter second number: ";
        while (!(cin >> num2)) {
            cout << "Invalid input. Please enter a valid integer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Input: Operator
        cout << "Enter operator (+, -, *, /): ";
        cin >> op;

        // Operation selection
        switch (op) {
            case '+':
                cout << "Sum: " << num1 + num2 << endl;
                break;
            case '-':
                cout << "Difference: " << num1 - num2 << endl;
                break;
            case '*':
                product(num1, num2);
                break;
            case '/':
                quotient(num1, num2);
                break;
            default:
                cout << "Error: Invalid operator!" << endl;
        }

        // Ask user to continue or not
        do {
            cout << "Do you want to perform another operation? (y/n): ";
            cin >> choice;
            choice = tolower(choice);
            if (choice != 'y' && choice != 'n') {
                cout << "Invalid choice. Please enter 'y' or 'n'.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (choice != 'y' && choice != 'n');

        cout << endl;

    } while (choice == 'y');

    // Exit message
    cout << "Thank you for using the calculator. Goodbye!" << endl;
    return 0;
}

/* ============================================================================
 Function  : product
 Purpose   : Prints the product of two integers
 Parameters: double a - first number
             double b - second number
 Returns   : void
============================================================================ */
void product(double a, double b) {
    cout << "Product: " << a * b << endl;
}

/* ============================================================================
 Function  : quotient
 Purpose   : Returns the quotient of two numbers
 Parameters: double a - numerator
             double b    - denominator
 Returns   : Void
============================================================================ */
void quotient(double a, double b) {
    if (b == 0) {
        cout << "Error: Division by zero!" << endl;
        return;
    }
    cout << "Quotient: " << a / b << endl;
}
