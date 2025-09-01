/*
 ====================================================================
  Quotient Function Program
 --------------------------------------------------------------------
  Description:
    This program defines a function `quotient` that calculates and 
    returns the quotient of a double and an integer. The main function 
    repeatedly prompts the user to enter a numerator (double) and 
    a denominator (integer), validates the input, and displays the 
    result using the `quotient` function.

    After each operation, the user is asked whether they want to 
    perform another division. The program continues until the 
    user enters 'n' or 'N' to quit.

  Features:
    - Computes and displays the quotient of a double and an integer
    - Validates inputs (numerator as double, denominator as non-zero int)
    - Repeats based on user choice with case-insensitive handling

  Author: [CS section 1, group 5 members]
  Date: [June 6, 2025]
 ====================================================================
*/

#include <iostream>                     // Required for input and output operations
#include <limits>                       // Provides numeric limits for input validation
#include <cctype>                       // Provides functions like tolower() for character handling
using namespace std;                    // Allows use of standard names like cin and cout directly

// Constant Definitions
const double ERROR_DIV_ZERO = 0.0;      // Return value when division by zero occurs

// Function Prototype
double quotient(double a, int b);       // Declares the function that returns the quotient

// Main program starts here
int main() {
    double a;                           // Variable to store the numerator
    int b;                              // Variable to store the denominator
    char choice;                        // Variable to store user's choice to continue or not

    // Descriptive welcome message
    cout << "==================================================\n";
    cout << "      Welcome to the Quotient Calculator Program   \n";
    cout << " This program divides a number by an integer you   \n";
    cout << " provide and displays the result. You can repeat   \n";
    cout << " this process until you choose to quit by entering \n";
    cout << " 'n' or 'N'.                                        \n";
    cout << "==================================================\n\n";

    do {
        // Prompt the user to enter the numerator (double)
        cout << "Enter any number for numerator: ";
        while (!(cin >> a)) {
            cout << "Invalid input. Please enter a valid number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Prompt the user to enter the denominator (non-zero integer)
        cout << "Enter an integer for denominator: ";
        while (!(cin >> b) || b == 0) {
            if (cin.fail()) {
                cout << "Invalid input. Please enter a valid integer: ";
            } else {
                cout << "Error: Denominator cannot be zero. Please enter a non-zero integer: ";
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Display the result using the quotient function
        cout << "Quotient of a and b: " << quotient(a, b) << endl;

        // Ask the user whether they want to repeat the process
        do {
            cout << "Do you want to divide another pair of numbers? (y/n): ";
            cin >> choice;
            choice = tolower(choice);  // Convert to lowercase for consistency

            if (choice != 'y' && choice != 'n') {
                cout << "Invalid choice. Please enter 'y' or 'n'.\n";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

        } while (choice != 'y' && choice != 'n');       // Repeat until valid choice is entered

    } while (choice == 'y');                            // Continue loop if user enters 'y'

    // Exit message
    cout << "Thank you for using the program. Goodbye!" << endl;
    return 0;                                           // End of program
}

/* ============================================================================
 Function  : quotient
 Purpose   : Returns the quotient of a double and an integer
 Parameters: double a - numerator
             int b    - denominator
 Returns   : double - result of division or ERROR_DIV_ZERO if b is zero
============================================================================ */
double quotient(double a, int b) {
    if (b == 0) {
        cout << "Error: Division by zero!" << endl;
        return ERROR_DIV_ZERO;
    }
    return a / b;
}
