/*
 ====================================================================
  Sum and Average of Three Integers
 --------------------------------------------------------------------
  Description:
    This C++ program prompts the user to enter three integer values.
    It calculates and displays their sum and average using a function
    named `Process`.

  Features:
    - Validates input to ensure only integers are accepted
    - Allows quitting by entering 'q' or 'Q'
    - Performs sum and average calculations within a separate function
    - Provides formatted output of the results

  Author: [CS secttion 1, group 5]
  Date: [June 6, 2025]
 ====================================================================
*/

#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Function to compute sum and average of three integers
void Process(int a, int b, int c, int& s, double& g) {
    s = a + b + c;
    g = s / 3.0;
}

// Function to validate input is a valid integer (not float, not char)
bool isValidInteger(const string& input) {
    if (input.empty() || (input[0] != '-' && !isdigit(input[0]) && input[0] != '+')) return false;

    for (size_t i = (input[0] == '-' || input[0] == '+') ? 1 : 0; i < input.length(); i++) {
        if (!isdigit(input[i])) return false;
    }
    return true;
}

int main() {
    string input;
    int num1, num2, num3;
    int sum;
    double average;

    cout << "---------------------------------------------\n";
    cout << "Welcome to the Integer Sum & Average Program!\n";
    cout << "Enter three integers and get the sum & average.\n";
    cout << "To quit at any time, type 'q' or 'Q'.\n";
    cout << "---------------------------------------------\n\n";

    while (true) {
        // Get first integer
        while (true) {
            cout << "Enter the first integer (or q to quit): ";
            cin >> input;
            if (input == "q" || input == "Q") {
                cout << "\nThank you for using the program. Goodbye!\n";
                return 0;
            }
            if (!isValidInteger(input)) {
                cout << "Invalid input. Please enter a valid integer.\n";
            } else {
                num1 = stoi(input);
                break;
            }
        }

        // Get second integer
        while (true) {
            cout << "Enter the second integer (or q to quit): ";
            cin >> input;
            if (input == "q" || input == "Q") {
                cout << "\nThank you for using the program. Goodbye!\n";
                return 0;
            }
            if (!isValidInteger(input)) {
                cout << "Invalid input. Please enter a valid integer.\n";
            } else {
                num2 = stoi(input);
                break;
            }
        }

        // Get third integer
        while (true) {
            cout << "Enter the third integer (or q to quit): ";
            cin >> input;
            if (input == "q" || input == "Q") {
                cout << "\nThank you for using the program. Goodbye!\n";
                return 0;
            }
            if (!isValidInteger(input)) {
                cout << "Invalid input. Please enter a valid integer.\n";
            } else {
                num3 = stoi(input);
                break;
            }
        }

        // Call the Process function
        Process(num1, num2, num3, sum, average);

        // Display results
        cout << "\nResults:\n";
        cout << "Sum = " << sum << endl;
        cout << "Average = " << average << endl;
        cout << "---------------------------------------------\n\n";

        // Ask user if they want to compute again, with input validation
        string cont;
        while (true) {
            cout << "Do you want to compute again? (y/n): ";
            cin >> cont;

            if (cont == "y" || cont == "Y") {
                cout << endl;
                break;  // continue outer while loop
            } else if (cont == "n" || cont == "N") {
                cout << "\nThank you for using the program. Goodbye!\n";
                return 0;
            } else {
                cout << "Invalid input. Please enter 'y' for yes or 'n' for no.\n";
            }
        }
    }

    return 0;
}
