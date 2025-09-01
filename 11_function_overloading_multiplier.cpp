/*
---------------------------------------------------------------
 Program: Multiply Using Function Overloading
 Language: C++
 Author: [CS secttion 1, group 5]
 Date: [June 7, 2025]

 Description:
    This program demonstrates the concept of function overloading 
    in C++. It defines three overloaded functions named 'multiply' 
    that each take a different data type as a parameter: int, float, 
    and double.

    The user is prompted to select a data type, input a value of 
    that type, and the program multiplies the value by 2 using the 
    appropriate overloaded function.

    Input validation is included to handle incorrect data types and 
    menu options. The user can choose to perform multiple 
    multiplications in a loop until they decide to exit.

 Features:
    - Function Overloading
    - Input Validation
    - User Interaction Loop
---------------------------------------------------------------
*/

#include <iostream>
#include <limits>
using namespace std;

// Multiply function for int
void multiply(int value) {
    cout << "Int multiplied by 2: " << value * 2 << endl;
}

// Multiply function for float
void multiply(float value) {
    cout << "Float multiplied by 2: " << value * 2 << endl;
}

// Multiply function for double
void multiply(double value) {
    cout << "Double multiplied by 2: " << value * 2 << endl;
}

int main() {
    string choice;

    cout << "--------------------------------------------------\n";
    cout << " Welcome to the Function Overloading Multiplier!\n";
    cout << "--------------------------------------------------\n";
    cout << " This program allows you to multiply an int, float,\n";
    cout << " or double value by 2 using overloaded functions.\n";
    cout << " You will be prompted to choose the data type,\n";
    cout << " then enter a number, and see the result.\n";
    cout << "--------------------------------------------------\n";

    do {
        int type;

        cout << "\nChoose data type:\n";
        cout << "1. int\n";
        cout << "2. float\n";
        cout << "3. double\n";

        // Input validation loop for type selection
        while (true) {
            cout << "Enter your choice (1-3): ";
            cin >> type;

            if (cin.fail() || type < 1 || type > 3) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Error: Please enter a valid number (1-3).\n";
            } else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear rest of the line
                break;
            }
        }

        // Input and validation for each type
        if (type == 1) {
            int val;
            cout << "Enter an integer value: ";
            while (!(cin >> val)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Error: Please enter a valid integer: ";
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            multiply(val);
        }
        else if (type == 2) {
            float val;
            cout << "Enter a float value: ";
            while (!(cin >> val)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Error: Please enter a valid float: ";
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            multiply(val);
        }
        else if (type == 3) {
            double val;
            cout << "Enter a double value: ";
            while (!(cin >> val)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Error: Please enter a valid double: ";
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            multiply(val);
        }

        // Ask if user wants to continue
        while (true) {
            cout << "\nDo you want to multiply another number? (y/n): ";
            cin >> choice;

            if (choice == "y" || choice == "Y" || choice == "n" || choice == "N") {
                break;
            } else {
                cout << "Please enter (Y) for yes or (N) for no.\n";
            }
        }

    } while (choice == "y" || choice == "Y");

    cout << "\nThank You for using our Program. Goodbye!" << endl;
    return 0;
}
