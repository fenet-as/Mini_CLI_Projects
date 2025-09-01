/*
 ====================================================================
  Class Average Calculator Program
 --------------------------------------------------------------------
  Description:
    This program collects marks of 10 students from user input.
    It validates each mark to ensure it is numeric and within the
    range 0 to 100. It then calculates and displays the class average.
    After displaying the result, the user is asked if they want to
    calculate another class average. The program repeats until the
    user chooses to quit by entering 'n' or 'N'.

  Features:
    - Uses a while loop to input marks for 10 students
    - Validates numeric input and input range (0-100)
    - Calculates and displays class average
    - Repeats based on user choice with case-insensitive handling

  Author: [CS section 1, group 5]
  Date: [June 6, 2025]
 ====================================================================
*/

#include <iostream>                     // Required for input and output operations
#include <limits>                       // Provides numeric limits for input validation
#include <cctype>                       // Provides tolower() for character handling
using namespace std;                   // Allows use of standard names like cin and cout directly


// Main program starts here
int main() {
    const int totalStudents = 10;      // Total number of students
    char choice;                       // Variable to store user's choice to continue or not

    // Welcome message
cout << "=========================================\n";
cout << "     Welcome to the Class Average Calculator\n";
cout << "-----------------------------------------\n";
cout << "Enter marks for 10 students (0-100).\n";
cout << "The program calculates and displays the\n";
cout << "class average. You can repeat or exit.\n";
cout << "=========================================\n\n";



    do {
        int count = 0;                 // Counter for marks entered
        double mark;                   // Current student's mark
        double sum = 0.0;              // Sum of all marks

        // Input loop for marks
        while (count < totalStudents) {
            cout << "Enter mark for student #" << (count + 1) << ": ";

            if (!(cin >> mark)) {          // Check if input is numeric
                cout << "Invalid input. Please enter a numeric value.\n";
                cin.clear();               // Clear error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                continue;                 // Retry input for same student
            }

            if (mark < 0 || mark > 100) {  // Check valid range
                cout << "Invalid input. Please enter marks between 0 and 100.\n";
                continue;                 // Retry input for same student
            }

            sum += mark;                  // Add valid mark to sum
            count++;                     // Increment count
        }

        double average = sum / totalStudents; // Calculate average

        // Display result
        cout << "\n==============================================\n";
        cout << "Class Average: " << average << endl;
        cout << "==============================================\n";

        // Ask user if they want to run again
        do {
            cout << "Do you want to calculate another class average? (y/n): ";
            cin >> choice;
            choice = tolower(choice);

            if (choice != 'y' && choice != 'n') {
                cout << "Invalid choice. Please enter 'y' or 'n'.\n";
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
            }
        } while (choice != 'y' && choice != 'n');

        // Clear input buffer to avoid issues on next loop
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (choice == 'y');           // Repeat if user wants

    cout << "Thank you for using the Class Average Calculator. Goodbye!\n";

    return 0;
}
