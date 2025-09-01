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
#include <string>                       // For getline and string handling
#include <sstream>                      // For stringstream parsing
using namespace std;                    // Allows use of standard names like cin and cout directly


// Function Prototype
int sum_from_to(int first, int last);  // Declares the function that returns the sum of integers from first to last


// Helper function to validate if a string represents a valid integer
bool is_valid_int(const string& s, int& value) {
    stringstream ss(s);
    ss >> value;
    // Check if entire string was used and conversion succeeded
    return !ss.fail() && ss.eof();
}


// Main program starts here
int main() {
    int start, end;                    // Variables to store the two integers
    char choice;                      // Variable to store user's choice to continue or not
    string input;                    // To read full lines for validation

    // Descriptive welcome message
    cout << "==================================================\n";
    cout << "       Welcome to the Sum From To Calculator       \n";
    cout << " This program sums all integers between two numbers \n";
    cout << " you provide (inclusive). You can repeat this      \n";
    cout << " process as many times as you like until you choose\n";
    cout << " to quit by entering 'n'.                           \n";
    cout << "==================================================\n\n";

    do {
        // Prompt the user to enter the first integer with validation
        cout << "\nEnter the first integer: ";
        while (true) {
            getline(cin, input);
            if (is_valid_int(input, start)) {
                break;
            } else {
                cout << "Invalid input. Please enter an integer: ";
            }
        }

        // Prompt the user to enter the second integer with validation
        cout << "\nEnter the second integer: ";
        while (true) {
            getline(cin, input);
            if (is_valid_int(input, end)) {
                break;
            } else {
                cout << "Invalid input. Please enter an integer: ";
            }
        }

        // Call sum_from_to function and display the result
        cout << "\nSum of integers from " << start << " to " << end << " is: " << sum_from_to(start, end) << endl;

        // Ask the user whether they want to repeat the process
        do {
            cout << "\nDo you want to sum another range of integers? (y/n): ";
            getline(cin, input);
            if (input.length() == 1) {
                choice = tolower(input[0]);                     // Convert choice to lowercase for consistency

                if (choice == 'y' || choice == 'n') {
                    break;
                }
            }
            cout << "Invalid choice. Please enter 'y' or 'n'.\n";
        } while (true);

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
