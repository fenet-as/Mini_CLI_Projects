/*
 ====================================================================
  Symmetric Star Pattern Program - Iterative and Recursive Methods
 --------------------------------------------------------------------
  Description:
    This program prints a symmetric star pattern based on a given
    positive integer input from the user. The pattern decreases from
    `n` to 1 stars, and then increases back from 1 to `n` stars.

    The user can choose between iterative or recursive method for 
    generating the pattern. After displaying the pattern, the user 
    is prompted whether they wish to run the program again.

  Features:
    - Generates symmetric star patterns
    - Offers both iterative and recursive solutions
    - Robust input validation
    - Repeats based on user choice with case-insensitive handling

  Author: [CS section 1, group 5]
  Date  : [June 6, 2025]
 ====================================================================
*/

#include <iostream>                     // Required for input and output operations
#include <limits>                       // Provides numeric limits for input validation
#include <cctype>                       // For tolower() function
using namespace std;                   // Allows use of standard names like cin and cout directly

// Function Prototypes
void printPatternIterative(int num);                   // Iterative pattern function
void printPatternRecursive(int num);                   // Recursive pattern function
void printDecreasing(int n);                           // Helper: recursive decreasing stars
void printIncreasing(int n, int current = 1);          // Helper: recursive increasing stars

// Main program starts here
int main() {
    int x;                                // Variable to store the input number
    char choice;                          // Variable to store user's decision to repeat
    char method;                          // Variable to store method choice (I or R)

    // Welcome message
    cout << "=====================================================\n";
    cout << "         Symmetric Star Pattern Generator            \n";
    cout << " This program prints a star pattern symmetrically    \n";
    cout << " using either an iterative or recursive approach.    \n";
    cout << "=====================================================\n\n";

    do {
        // Prompt and validate positive integer input
        cout << "Enter a positive integer: ";
        while (!(cin >> x) || x <= 0) {
            cout << "Invalid input. Please enter a positive integer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Prompt for method choice
        cout << "Choose method - Iterative (I/i) or Recursive (R/r): ";
        cin >> method;
        method = tolower(method);         // Normalize method input to lowercase

        // Display pattern based on user choice
        if (method == 'i') {
            printPatternIterative(x);
        } else if (method == 'r') {
            printPatternRecursive(x);
        } else {
            cout << "Invalid method selected. Please choose 'I' or 'R'.\n";
        }

        // Ask user whether they want to continue
        do {
            cout << "\nDo you want to run the program again? (y/n): ";
            cin >> choice;
            choice = tolower(choice);

            if (choice != 'y' && choice != 'n') {
                cout << "Invalid choice. Please enter 'y' or 'n'.\n";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

        } while (choice != 'y' && choice != 'n');

    } while (choice == 'y');

    cout << "\nThank you for using the pattern generator. Goodbye!\n";
    return 0;
}

/* ============================================================================
 Function  : printPatternIterative
 Purpose   : Prints a symmetric star pattern using loops
 Parameters: int num - the number of stars in the first/last row
============================================================================ */
void printPatternIterative(int num) {
    for (int i = num; i >= 1; i--) {
        for (int j = 0; j < i; j++) {
            cout << "* ";
        }
        cout << endl;
    }

    for (int i = 1; i <= num; i++) {
        for (int j = 0; j < i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

/* ============================================================================
 Function  : printPatternRecursive
 Purpose   : Prints a symmetric star pattern using recursion
 Parameters: int num - the number of stars in the first/last row
============================================================================ */
void printPatternRecursive(int num) {
    printDecreasing(num);
    printIncreasing(num);
}

/* ============================================================================
 Function  : printDecreasing
 Purpose   : Prints decreasing star lines recursively
 Parameters: int n - current number of stars to print
============================================================================ */
void printDecreasing(int n) {
    if (n == 0) return;
    for (int i = 0; i < n; i++) cout << "* ";
    cout << endl;
    printDecreasing(n - 1);
}

/* ============================================================================
 Function  : printIncreasing
 Purpose   : Prints increasing star lines recursively
 Parameters: int n - maximum number of stars
             int current - current line number
============================================================================ */
void printIncreasing(int n, int current) {
    if (current > n) return;
    for (int i = 0; i < current; i++) cout << "* ";
    cout << endl;
    printIncreasing(n, current + 1);
}
