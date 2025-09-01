/*
 ====================================================================
  Reverse Float Array with Input Validation
 --------------------------------------------------------------------
  Description:
    This C++ program prompts the user to input the size of a float array,
    validating that the size is a positive integer (non-zero). The user 
    then enters float values to populate the array. The program reverses 
    the array contents in-place and displays the reversed array in a formatted output.

  Features:
    - Validates that array size is numeric and greater than zero
    - Allows quitting by entering 'q' or 'Q'
    - Reverses the float array in-place
    - Displays the reversed array with formatted output
    - Prompts user if they want to run the program again (only 'y' or 'n' accepted)

  Author: [CS secttion 1, group 5]
  Date: [June 5, 2025]
 ====================================================================
*/

#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Maximum allowed size of the array
const int MAX_SIZE = 10000;

// Function to reverse the elements of a float array
void reverse(float array[], int size) {
    int startIndex = 0, endIndex = size - 1;
    float temp;

    while (startIndex < endIndex) {
        temp = array[startIndex];
        array[startIndex] = array[endIndex];
        array[endIndex] = temp;
        startIndex++;
        endIndex--;
    }
}

// Function to validate that input is a positive, non-zero integer
bool isValidInput(string input) {
    if (input.empty() || input == "0") return false;

    for (int index = 0; index < input.length(); index++) {
        if (!isdigit(input[index])) return false;
    }

    return true;
}

int main() {
    string inputString;
    int arraySize;

    // Descriptive startup message
    cout << "---------------------------------------------\n";
    cout << "Welcome to the Float Array Reversal Program!\n";
    cout << "This program allows you to enter float numbers\n";
    cout << "into an array and then reverses the array.\n";
    cout << "To quit at any time, type 'q'.\n";
    cout << "---------------------------------------------\n\n";

    while (true) {
        cout << "Enter the size of your array : ";
        cin >> inputString;

        if (inputString == "Q" || inputString == "q") {
            break;
        }

        if (!isValidInput(inputString)) {
            cout << "Invalid input, please input a valid size of array.\n";
            continue;
        }

        arraySize = stoi(inputString);

        if (arraySize > MAX_SIZE) {
            cout << "Array size too large. Please enter a size less than or equal to " << MAX_SIZE << ".\n";
            continue;
        }

        float numbers[arraySize];

        for (int index = 0; index < arraySize; index++) {
            while (true) {
                cout << "Enter the float element " << index + 1 << " : ";
                cin >> numbers[index];

                if (cin.fail()) {
                    cin.clear(); // clear error flags
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
                    cout << "Invalid input. Please enter a valid float value.\n";
                } else {
                    break; // valid input
                }
            }
        }

        reverse(numbers, arraySize);

        cout << "The reversed array is : " << endl;
        cout << "[";
        for (int index = 0; index < arraySize; index++) {
            if (index == arraySize - 1) {
                cout << numbers[index];
                break;
            }
            cout << numbers[index] << ",";
        }
        cout << "]\n";

        // Ask user if they want to reverse another array (strict yes/no)
        string choice;
        while (true) {
            cout << "\nDo you want to reverse another array? (y/n): ";
            cin >> choice;
            if (choice == "y" || choice == "Y") {
                cout << endl;
                break;  // Continue outer main loop
            } else if (choice == "n" || choice == "N") {
                cout << "\nThank you for using the program. GoodBye!" << endl;
                return 0;  // Exit program immediately
            } else {
                cout << "\nPlease enter 'y' for yes or 'n' for no." << endl;
            }
        }
    }

    return 0;
}
