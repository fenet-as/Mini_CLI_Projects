/*
 ====================================================================
  Decimal to Binary Converter (Recursive)
 --------------------------------------------------------------------
  Description:
    This program defines a recursive function `decToBin` that 
    calculates and prints the binary representation of a non-negative 
    decimal number. The program repeatedly prompts the user to 
    enter a non-negative integer, validates the input, and displays 
    its binary form.

    After each conversion, the user is asked whether they want to 
    convert another number. The program continues until the user 
    enters 'n' or 'N' to quit.

  Features:
    - Converts a decimal number to binary using recursion
    - Robust input validation for non-negative integers
    - Repeats based on user choice with case-insensitive handling

  Author: [CS section 1, group 5 members]
  Date: [June 5, 2025]
 ====================================================================
*/

#include <iostream>                     // Required for input and output operations
#include <limits>                       // Provides numeric limits for input validation
#include <cctype>                       // Provides functions like tolower() for character handling
#include <string>                       // Added for string input handling
using namespace std;                   // Allows use of standard names like cin and cout directly


// Function Prototype
void decToBin(int num, int base);       // Declares the recursive function that prints binary


// Main program starts here
int main() {
    int number;                         // Variable to store the input number
    char choice;                        // Variable to store user's choice to continue or not
    string input;                      // Variable to hold user input as string for validation

    // Descriptive welcome message
    cout << "==================================================\n";
    cout << "        Welcome to Decimal to Binary Converter     \n";
    cout << " This program converts decimal numbers into binary \n";
    cout << " using a recursive algorithm. You can repeat this  \n";
    cout << " process as many times as you like until you choose\n";
    cout << " to quit by entering 'n'.                           \n";
    cout << "==================================================\n\n";

    do {
        // Prompt the user to enter a non-negative integer
        cout << "Enter a non-negative integer: ";

        // Input validation loop modified to handle floats properly
        while (true) {
            cin >> input;

            // Check if input contains only digits
            bool valid = true;
            for (char c : input) {
                if (!isdigit(c)) {
                    valid = false;
                    break;
                }
            }

            if (!valid) {
                cout << "Invalid input. Please enter a non-negative integer: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            try {
                number = stoi(input);
            } catch (...) {
                cout << "Invalid input. Please enter a non-negative integer: ";
                continue;
            }

            break;  // Valid input received, exit loop
        }

        // Display binary representation
        cout << "Binary representation of " << number << " = ";
        if (number == 0)
            cout << 0;
        else
            decToBin(number, 2);
        cout << endl;

        // Ask the user whether they want to convert another number
        do {
            cout << "Do you want to convert another number? (y/n): ";
            cin >> choice;
            choice = tolower(choice);

            if (choice != 'y' && choice != 'n') {
                cout << "Invalid choice. Please enter 'y' or 'n'.\n";
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
            }

        } while (choice != 'y' && choice != 'n');       // Repeat until valid choice is entered

    } while (choice == 'y');                            // Repeat main loop if user enters 'y'

    // Exit message
    cout << "Thank you for using the program. Goodbye!" << endl;
    return 0;                                           // End of program
}

/* ============================================================================
 Function  : decToBin
 Purpose   : Recursively prints the binary representation of a number
 Parameters: int num  - the number to convert
             int base - the base to convert to (always 2 in this case)
============================================================================ */

void decToBin(int num, int base) {
    if (num == 0)
        return;
    decToBin(num / base, base);
    cout << num % base;
}
