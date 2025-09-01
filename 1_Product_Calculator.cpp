/*
 ====================================================================
  Product Function Program
 --------------------------------------------------------------------
  Description:
    This program defines a function `product` that calculates and 
    prints the product of two integers. The main function repeatedly 
    prompts the user to enter two integers, validates the input, and 
    displays the result using the `product` function.

    After each operation, the user is asked whether they want to 
    perform another multiplication. The program continues until the 
    user enters 'n' or 'N' to quit.

  Features:
    - Computes and displays the product of two integers
    - Robust input validation for integers
    - Repeats based on user choice with case-insensitive handling

  Author: [CS secttion 1, group 5 members]
  Date: [June 6, 2025]
 ====================================================================
*/


#include <iostream>                     // Required for input and output operations
#include <limits>                       // Provides numeric limits for input validation
#include <cctype>                       // Provides functions like tolower() for character handling
using namespace std;                   // Allows use of standard names like cin and cout directly


// Function Prototype
void product(int a, int b);            // Declares the function that prints the product of two integers


// Main program starts here
int main() {
    int x, y;                          // Variables to store the two integers
    char choice;                       // Variable to store user's choice to continue or not

    // Descriptive welcome message
    cout << "==================================================\n";
    cout << "       Welcome to the Integer Multiplier Program   \n";
    cout << " This program multiplies two integers you provide  \n";
    cout << " and displays their product. You can repeat this   \n";
    cout << " process as many times as you like until you choose\n";
    cout << " to quit by entering 'n'.                           \n";
    cout << "==================================================\n\n";

    do {
        // Prompt the user to enter the first integer
        cout << "Enter the first integer: ";
        while (!(cin >> x)) {                          // Input validation loop for the first integer
            cout << "Invalid input. Please enter an integer: ";
            cin.clear();                                // Clear error flag on cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }


        // Prompt the user to enter the second integer
        cout << "Enter the second integer: ";
        while (!(cin >> y)) {                          // Input validation loop for the second integer
            cout << "Invalid input. Please enter an integer: ";
            cin.clear();                                // Clear error flag on cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }


        product(x, y);                                  // Call the product function to display result


        // Ask the user whether they want to repeat the process
        do {
            cout << "Do you want to multiply another two integers? (y/n): ";
            cin >> choice;                              // Take user's choice
            choice = tolower(choice);                   // Convert choice to lowercase for consistency

            if (choice != 'y' && choice != 'n') {       // Validate choice
                cout << "Invalid choice. Please enter 'y' or 'n'.\n";
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
            }


        } while (choice != 'y' && choice != 'n');       // Repeat until valid choice is entered

    } while (choice == 'y');                            // Repeat main loop if user enters 'y'


    // Exit message
    cout << "Thank you for using the program.Goodbye!" << endl;
    return 0;                                           // End of program
}

/* ============================================================================
 Function  : product
 Purpose   : Prints the product of two integers
 Parameters: int a - first integer
             int b - second integer
============================================================================ */

void product(int a, int b) {
    cout << "Product: " << a * b << endl;              // Output the result of a multiplied by b
}
