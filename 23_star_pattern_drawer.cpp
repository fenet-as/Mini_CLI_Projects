/*
 ====================================================================
  Star Pattern Drawing Program
 --------------------------------------------------------------------
  Description:
    This program interacts with the user to draw a star pattern or quit.
    - If the user enters 'Y' or 'y', it draws the pattern using nested loops.
    - If the user enters 'Q' or 'q', the program exits.
    - For any other alphanumeric input, the program informs the user that
      the input is not recognized.

    The program repeats this interaction until the user chooses to quit.

  Features:
    - Uses nested for-loops to draw the star pattern
    - Case-insensitive input handling for user commands
    - User input validation with informative messages

  Author: [CS section 1, group 5]
  Date: [June 11, 2025]
 ====================================================================
*/

#include <iostream>        // Required for input and output operations
#include <limits>          // Provides numeric limits for input validation
#include <cctype>          // Provides functions like tolower() and isalnum() for character handling

using namespace std;       // Allows use of standard names like cin and cout directly

// Function prototype
void drawPattern();        // Declares the function that prints the star pattern


// Main program starts here
int main() {
    char choice;           // Variable to store user's menu choice

    // Descriptive welcome message
    cout << "=========================================================\n";
    cout << "         Welcome to the Star Pattern Drawing Program      \n";
    cout << " This program draws a star pattern when you enter 'Y' or  \n";
    cout << " 'y'. Enter 'Q' or 'q' to quit. For any other input, the  \n";
    cout << " program will notify you that the input is not recognized.\n";
    cout << "=========================================================\n\n";

    do {
        // Prompt user for input
        cout << "Do you want to draw the pattern or quit?" << endl;
        cout << "Y (or y) = Draw pattern" << endl;
        cout << "Q (or q) = Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Convert choice to lowercase for case-insensitive comparison
        choice = tolower(choice);

        if (choice == 'y') {
            drawPattern();      // Call function to draw the pattern

            // Wait for user to press Enter before continuing
            cout << "\nPress Enter to continue...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear input buffer
            cin.get();
        }
        else if (choice == 'q') {
            cout << "Program will now exit." << endl;
        }
        else if (isalnum(choice)) {
            cout << "Input '" << choice << "' is not recognized. Please try again." << endl;

            cout << "Press Enter to continue...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }
        else {
            // Handle non-alphanumeric inputs gracefully
            cout << "Input '" << choice << "' is not recognized. Please try again." << endl;

            cout << "Press Enter to continue...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }

    } while (choice != 'q');   // Continue looping until user chooses to quit

    // Exit message
    cout << "Thank you for using the program. Goodbye!" << endl;

    return 0;                 // End of program
}

/* ============================================================================
 Function  : drawPattern
 Purpose   : Prints a star pattern with alternating indented lines
 Parameters: None
============================================================================= */
void drawPattern() {
    for (int i = 0; i < 8; ++i) {               // 8 lines total
        if (i % 2 == 1)                         // Odd lines start with one leading space
            cout << " ";

        for (int j = 0; j < 9; ++j) {           // Print 9 stars separated by spaces
            cout << "*";
            if (j != 8)                        // Print space after star except last one
                cout << " ";
        }
        cout << endl;
    }
}
