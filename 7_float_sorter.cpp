/*
 ====================================================================
  Sort Three Floating-Point Numbers
 --------------------------------------------------------------------
  Description:
    This program prompts the user to enter three floating-point numbers 
    and sorts them in ascending order using the `sort3` function. User 
    inputs are accepted as strings and validated to ensure they represent 
    valid floating-point numbers, including negative values and decimals.

    The program continues to prompt for input until the user enters 'q' or 'Q' to quit.
    Validation is done via a custom `isValidInput` function, with appropriate 
    error handling during conversion.

  Features:
    - Validates string input to confirm valid floating-point format
    - Sorts three numbers in-place using reference parameters
    - Supports repeated execution until user quits

  Usage:
    Compile and run the program. Enter three numbers to see them sorted, 
    or enter 'q' at any prompt to quit.

  Author: [CS secttion 1, group 5]
  Date: [June 3, 2025]
 ====================================================================
*/

#include <iostream>
#include <string>
using namespace std;

// Sort three floats in ascending order
void sort3(float &num1, float &num2, float &num3) {
    if (num1 > num2) {
        float temp = num1;
        num1 = num2;
        num2 = temp;
    }
    if (num2 > num3) {
        float temp = num2;
        num2 = num3;
        num3 = temp;
    }
    if (num1 > num2) {
        float temp = num1;
        num1 = num2;
        num2 = temp;
    }
}

// Validate if a string is a valid float
bool isValidInput(string inputStr) {
    if (inputStr.empty()) return false;

    int dotCount = 0;
    bool hasDigit = false;

    for (int i = 0; i < inputStr.length(); i++) {
        if (i == 0 && inputStr[i] == '-') continue;

        if (inputStr[i] == '.') {
            dotCount++;
            if (dotCount > 1) return false;
            continue;
        }

        if (isdigit(inputStr[i])) {
            hasDigit = true;
            continue;
        }

        return false;
    }

    return hasDigit;
}

int main() {
    cout << "---------------------------------------------" << endl;
    cout << "Welcome to the Float Sorter!" << endl;
    cout << "This program takes three floating-point numbers" << endl;
    cout << "and sorts them in ascending order." << endl;
    cout << "You can enter 'q' at any time to quit." << endl;
    cout << "---------------------------------------------" << endl << endl;

    string input;
    float number1, number2, number3;

    while (true) {
        // Input for number 1
        while (true) {
            cout << "Enter the first number (or q to quit): ";
            cin >> input;
            if (input == "q" || input == "Q") {
                cout << "GoodBye" << endl;
                return 0;
            }
            if (isValidInput(input)) {
                try {
                    number1 = stof(input);
                    break; // Valid input, proceed to next
                } catch (...) {
                    cout << "Conversion failed. Please enter a valid number." << endl;
                }
            } else {
                cout << "Input a valid number." << endl;
            }
        }

        // Input for number 2
        while (true) {
            cout << "Enter the second number (or q to quit): ";
            cin >> input;
            if (input == "q" || input == "Q") {
                cout << "GoodBye" << endl;
                return 0;
            }
            if (isValidInput(input)) {
                try {
                    number2 = stof(input);
                    break;
                } catch (...) {
                    cout << "Conversion failed. Please enter a valid number." << endl;
                }
            } else {
                cout << "Input a valid number." << endl;
            }
        }

        // Input for number 3
        while (true) {
            cout << "Enter the third number (or q to quit): ";
            cin >> input;
            if (input == "q" || input == "Q") {
                cout << "GoodBye" << endl;
                return 0;
            }
            if (isValidInput(input)) {
                try {
                    number3 = stof(input);
                    break;
                } catch (...) {
                    cout << "Conversion failed. Please enter a valid number." << endl;
                }
            } else {
                cout << "Input a valid number." << endl;
            }
        }

        sort3(number1, number2, number3);
        cout << "The sorted numbers are: " << number1 << " , " << number2 << " , " << number3 << endl << endl;

        // Ask user if they want to compute again (strict yes/no)
        string choice;
        while (true) {
            cout << "Do you want to compute again? (y/n): ";
            cin >> choice;
            if (choice == "y" || choice == "Y") {
                cout<< endl;
                break;  // Continue the main loop
            } else if (choice == "n" || choice == "N") {
                cout << "\nThank you for using the program.GoodBye!" << endl;
                return 0;  // Exit the program immediately
            } else {
                cout << "\nPlease enter 'y' for yes or 'n' for no." << endl;
            }
        }
    }

    return 0;
}
