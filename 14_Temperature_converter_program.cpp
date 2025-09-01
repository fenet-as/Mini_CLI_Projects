/*
 ====================================================================
  Temperature Conversion Program
 --------------------------------------------------------------------
  Description:
    This program allows users to convert temperatures between 
    Fahrenheit and Celsius. Users can choose the type of conversion,
    input a temperature value (validated within the range -100 to 1000), 
    and receive the result with two decimal precision.


  Features:
    - Menu-driven user interface
    - Conversion in both directions (Fahrenheit <-> Celsius)
    - Input validation for temperature range and menu choice
    - Detection and handling of non-numeric temperature input
    - Option to perform multiple conversions in one run

  Author: [CS secttion 1, group 5]
  Date: [June 7, 2025]
 ====================================================================
*/

#include <iostream>
#include <iomanip>
using namespace std;

// Convert Fahrenheit to Celsius
double fahrenheitToCelsius(double f) {
    return (f - 32) * 5.0 / 9.0;
}

// Convert Celsius to Fahrenheit
double celsiusToFahrenheit(double c) {
    return (c * 9.0 / 5.0) + 32;
}

int main() {
    int choice;
    double temp;
    char again;

    // Welcome message
    cout << "============================================================\n";
    cout << "              Welcome to the Temperature Converter!\n";
    cout << "------------------------------------------------------------\n";
    cout << "This program allows you to convert temperatures between\n";
    cout << "Fahrenheit and Celsius. You can choose the conversion type,\n";
    cout << "enter a temperature, and view the result.\n";
    cout << "Valid temperature range: -100 to 1000 degrees.\n";
    cout << "Let's get started!\n";
    cout << "============================================================\n\n";

    do {
        // Ask for a valid conversion type
        do {
            cout << "Press 1 to convert Fahrenheit to Celsius\n";
            cout << "Press 2 to convert Celsius to Fahrenheit\n";
            cout << "Your choice: ";
            cin >> choice;

            if (choice != 1 && choice != 2) {
                cout << "\nInvalid choice. Please enter 1 or 2.\n\n";
            }

        } while (choice != 1 && choice != 2);

        cout << fixed << setprecision(2);

        // Input with validation including non-numeric check
        while (true) {
            if (choice == 1) {
                cout << "\nEnter the temperature in Fahrenheit (-100 to 1000 accepted): ";
            } else {
                cout << "\nEnter the temperature in Celsius (-100 to 1000 accepted): ";
            }

            cin >> temp;

            // Check for invalid input (non-numeric)
            if (cin.fail()) {
                cin.clear(); // clear error flags
                cin.ignore(10000, '\n'); // discard bad input
                cout << "Invalid input. Please enter a numeric value.\n";
                continue;
            }

            // Check valid temperature range
            if (temp < -100 || temp > 1000) {
                cout << "Temperature out of range. Please try again.\n";
                continue;
            }

            break; // valid input
        }

        if (choice == 1) {
            cout << "In Celsius that is : " << fahrenheitToCelsius(temp) << "\n";
        } else {
            cout << "In Fahrenheit that is : " << celsiusToFahrenheit(temp) << "\n";
        }

        // Ask user if they want to try again
        while (true) {
            cout << "\nWould you like to convert another temperature? (Y/N): ";
            cin >> again;

            if (again == 'Y' || again == 'y' || again == 'N' || again == 'n') {
                break;
            } else {
                cout << "\nPlease enter either (Y) for yes or (N) for no.\n";
            }
        }

        cout << endl;

    } while (again == 'Y' || again == 'y');

    cout << "\nThank you for using the temperature converter. Goodbye!\n";
    return 0;
}
