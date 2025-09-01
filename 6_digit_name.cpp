/*
 ====================================================================
  Digit Name Printer
 --------------------------------------------------------------------
  Description:
    This program defines a function `digit_name` that prints the English 
    name of a digit (1–9) without a newline. If the input is outside this 
    range, it prints "digit error" followed by a newline.

    The main function prompts the user to enter a number from 1 to 9 
    (or 'q' to quit), validates the input, and calls the `digit_name` 
    function accordingly.

  Features:
    - Prints digit names for digits 1 through 9
    - Handles invalid digit inputs gracefully
    - User input validation with option to quit

  Author: [CS secttion 1, group 5]
  Date: [June 6, 2025]
 ====================================================================
*/


#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Prints the English name of a digit (1-9) without a newline.
// Prints "digit error" followed by a newline for invalid digits.
void digit_name(int digit) {
    switch (digit) {
        case 1: cout << "|The number you entered is - One"; break;
        case 2: cout << "|The number you entered is - Two"; break;
        case 3: cout << "|The number you entered is - Three"; break;
        case 4: cout << "|The number you entered is - Four"; break;
        case 5: cout << "|The number you entered is - Five"; break;
        case 6: cout << "|The number you entered is - Six"; break;
        case 7: cout << "|The number you entered is - Seven"; break;
        case 8: cout << "|The number you entered is - Eight"; break;
        case 9: cout << "|The number you entered is - Nine"; break;
        default: cout << "digit error.\n"; break;
    }
}

// Checks if a string represents a valid non-negative integer
bool is_valid_integer(const string& input) {
    if (input.empty()) return false;
    for (char ch : input) {
        if (!isdigit(ch)) return false;
    }
    return true;
}

int main() {
    string user_input;
    int number;

    // Introductory message
    cout << "Welcome to the Digit Name Program!" << endl;
    cout << "This program will print the English name of any digit from 1 to 9 you enter." << endl;
    cout << "If you enter a number outside this range, it will display 'digit error'." << endl;
    cout << "Type 'q' or 'Q' to quit the program at any time." << endl;
    cout << "------------------------------------------------------------" << endl;

    while (true) {
        cout << "|   Enter an integer to print the English name for : ";
        cin >> user_input;

        if (user_input == "q" || user_input == "Q") {
            cout << "Thank you for using the program." << endl;
            cout << "GoodBye!" << endl;
            break;
        }

        if (!is_valid_integer(user_input)) {
            cout << "Invalid input. Please enter a valid number." << endl;
            continue;
        }

        number = stoi(user_input);

        if (number >= 1 && number <= 9) {
            digit_name(number);  // Valid input, no newline
        } else {
            digit_name(number);  // Invalid digit, prints "digit error" + newline
        }
    }

    return 0;
}
