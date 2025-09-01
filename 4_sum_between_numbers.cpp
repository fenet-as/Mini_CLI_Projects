/*
 ====================================================================
  Sum From To Function Program
 --------------------------------------------------------------------
  Description:
    This program defines a function `sum_from_to` that calculates and 
    returns the sum of all integers between two given integers inclusive.
    The main function repeatedly prompts the user to enter two integers,
    validates the input, and displays the result using the `sum_from_to`
    function.

    After each operation, the user is asked whether they want to 
    perform another summation. The program continues until the 
    user enters 'n' or 'N' to quit.

  Features:
    - Computes and displays the sum of all integers between two values
    - Robust input validation for integers
    - Repeats based on user choice with case-insensitive handling

  Author: [CS section 1, group 5]
  Date: [June 6, 2025]
 ====================================================================
*/

#include <iostream>                     // Required for input and output operations
#include <limits>                       // Provides numeric limits for input validation
#include <cctype>                       // Provides functions like tolower() for character handling
using namespace std;                    // Allows use of standard names like cin and cout directly


// Function Prototype
int sum_from_to(int first, int last);  // Declares the function that returns the sum of integers from first to last


// Main program starts here
int main() {
    int start, end;                    // Variables to store the two integers
    char choice;                      // Variable to store user's choice to continue or not

    // Descriptive welcome message
    cout << "==================================================\n";
    cout << "       Welcome to the Sum From To Calculator       \n";
    cout << " This program sums all integers between two numbers \n";
    cout << " you provide (inclusive). You can repeat this      \n";
    cout << " process as many times as you like until you choose\n";
    cout << " to quit by entering 'n'.                           \n";
    cout << "==================================================\n\n";

    do {
        // Prompt the user to enter the first integer
        cout << "\nEnter the first integer: ";
        while (!(cin >> start)) {                          // Input validation loop for the first integer
            cout << "Invalid input. Please enter an integer: ";
            cin.clear();                                    // Clear error flag on cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }

        // Prompt the user to enter the second integer
        cout << "\nEnter the second integer: ";
        while (!(cin >> end)) {                            // Input validation loop for the second integer
            cout << "Invalid input. Please enter an integer: ";
            cin.clear();                                    // Clear error flag on cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }

        // Call sum_from_to function and display the result
        cout << "\nSum of integers from " << start << " to " << end << " is: " << sum_from_to(start, end) << endl;

        // Ask the user whether they want to repeat the process
        do {
            cout << "\nDo you want to sum another range of integers? (y/n): ";
            cin >> choice;                                // Take user's choice
            choice = tolower(choice);                     // Convert choice to lowercase for consistency

            if (choice != 'y' && choice != 'n') {        // Validate choice
                cout << "Invalid choice. Please enter 'y' or 'n'.\n";
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
            }

        } while (choice != 'y' && choice != 'n');         // Repeat until valid choice is entered

    } while (choice == 'y');                              // Repeat main loop if user enters 'y'

    // Exit message
    cout << "Thank you for using the program. Goodbye!" << endl;
    return 0;                                             // End of program
}

/* ============================================================================
 Function  : sum_from_to
 Purpose   : Returns the sum of all integers from first to last (inclusive)
 Parameters: int first - starting integer
             int last  - ending integer
 Returns   : int - sum of integers between first and last inclusive
============================================================================ */

int sum_from_to(int first, int last) {
    int sum = 0;
    if (first <= last) {
        for (int i = first; i <= last; ++i)
            sum += i;
    } else {
        for (int i = first; i >= last; --i)
            sum += i;
    }
    return sum;
}
