/*
 ====================================================================
  Enough Function Program
 --------------------------------------------------------------------
  Description:
    This program defines a function `enough` that calculates and 
    returns the smallest positive integer n such that the sum 
    1 + 2 + ... + n is at least equal to a given goal.

    The main function repeatedly prompts the user to enter a positive 
    integer goal, validates the input, and displays the result using 
    the `enough` function.

    After each operation, the user is asked whether they want to 
    perform another calculation. The program continues until the 
    user enters 'n' or 'N' to quit.

  Features:
    - Computes and displays the smallest n where sum 1..n >= goal
    - Robust input validation for positive integers
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
int enough(int goal);                   // Declares the function that returns smallest n with sum 1..n >= goal


// Main program starts here
int main() {
    int goal;                          // Variable to store the user’s goal input
    char choice;                      // Variable to store user’s choice to continue or not

    // Descriptive welcome message
    cout << "==================================================\n";
    cout << "        Welcome to the Enough Function Program      \n";
    cout << " This program finds the smallest positive integer n \n";
    cout << " such that 1 + 2 + ... + n is at least equal to your\n";
    cout << " given goal. You can repeat this process as many    \n";
    cout << " times as you like until you choose to quit by       \n";
    cout << " entering 'n'.                                       \n";
    cout << "==================================================\n\n";

    do {
        // Prompt the user to enter a positive integer goal
        cout << "\nEnter a positive integer goal: ";
        while (!(cin >> goal) || goal <= 0) {            // Input validation loop for positive integer
            cout << "Invalid input. Please enter a positive integer: ";
            cin.clear();                                  // Clear error flag on cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }

        // Call the enough function and display the result
        cout << "The smallest n with sum 1..n >= " << goal << " is: " << enough(goal) << endl;

        // Ask the user whether they want to repeat the process
        do {
            cout << "\nDo you want to try another goal? (y/n): ";
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
    return 0;                                            // End of program
}

/* ============================================================================ 
 Function  : enough
 Purpose   : Returns the smallest positive integer n such that 1+2+...+n >= goal
 Parameters: int goal - the target sum
 Returns   : int - the smallest n meeting the condition
============================================================================ */
int enough(int goal) {
    int sum = 0;
    int n = 0;
    while (sum < goal) {
        n++;
        sum += n;
    }
    return n;
}
