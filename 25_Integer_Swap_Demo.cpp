/*
 ====================================================================
  Integer Swap Demonstration (Pass-by-Value vs Pass-by-Reference)
 --------------------------------------------------------------------
  Description:
    This program takes two integers from the user and demonstrates 
    the difference between passing parameters by value and by reference.

    - swapInts(int, int): Swaps values using pass-by-value (no change in main).
    - swapIntsRef(int&, int&): Swaps values using pass-by-reference 
      (changes reflect in main).

    After each demonstration, the user is asked if they wish to repeat 
    the operation. The program continues until the user enters 'n' or 'N'.

  Features:
    - Compares the effects of pass-by-value vs. pass-by-reference
    - Robust input validation
    - Repeats based on user choice (case-insensitive)

  Author: [CS section 1, group 5]
  Date: [June 6, 2025]
 ====================================================================
*/

#include <iostream>                     // Required for input and output operations
#include <limits>                       // For input validation using numeric limits
#include <cctype>                       // For character case conversion functions

using namespace std;                   // Allows direct use of standard library names


// Function Prototypes
void swapInts(int x, int y);           // Swaps two integers using pass-by-value
void swapIntsRef(int& x, int& y);      // Swaps two integers using pass-by-reference


// Main Program Starts Here
int main() {
    int a, b;                           // Variables to hold user input
    char choice;                        // User's choice to repeat or not

    // Program Introduction
    cout << "==================================================\n";
    cout << "   Pass-by-Value vs Pass-by-Reference Demonstration\n";
    cout << " This program will swap two integers in two different\n";
    cout << " ways and show how each method affects the results.\n";
    cout << "==================================================\n\n";

    do {
        // Input: First Integer
        cout << "Enter the first integer: ";
        while (!(cin >> a)) {
            cout << "Invalid input. Please enter an integer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Input: Second Integer
        cout << "Enter the second integer: ";
        while (!(cin >> b)) {
            cout << "Invalid input. Please enter an integer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Display before swapping
        cout << "\nBefore swapping:\n";
        cout << "a = " << a << ", b = " << b << endl;

        // Pass-by-Value Swap
        swapInts(a, b);
        cout << "After swapInts (pass-by-value): a = " << a << ", b = " << b << endl;

        // Pass-by-Reference Swap
        swapIntsRef(a, b);
        cout << "After swapIntsRef (pass-by-reference): a = " << a << ", b = " << b << endl;

        // Ask user whether to continue
        do {
            cout << "\nDo you want to try again? (y/n): ";
            cin >> choice;
            choice = tolower(choice);

            if (choice != 'y' && choice != 'n') {
                cout << "Invalid choice. Please enter 'y' or 'n'.\n";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (choice != 'y' && choice != 'n');

        cout << "\n--------------------------------------------------\n";

    } while (choice == 'y');

    // Exit message
    cout << "\nThank you for using the program. Goodbye!" << endl;
    return 0;
}


/*
 ============================================================================
 Function  : swapInts
 Purpose   : Swaps two integers using pass-by-value (no effect outside)
 Parameters: int x - first integer
             int y - second integer
 ============================================================================
*/
void swapInts(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
    cout << "Inside swapInts (pass-by-value): a = " << x << ", b = " << y << endl;
}


/*
 ============================================================================
 Function  : swapIntsRef
 Purpose   : Swaps two integers using pass-by-reference (affects caller)
 Parameters: int& x - first integer (by reference)
             int& y - second integer (by reference)
 ============================================================================
*/
void swapIntsRef(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
    cout << "Inside swapIntsRef (pass-by-reference): a = " << x << ", b = " << y << endl;
}
