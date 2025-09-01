/*
    Program: Square Shape Drawer with Asterisks
    Author: [CS secttion 1, group 5]
    Date: [June 7, 2025]
    -------------------------------------------
    This program prompts the user to enter the size of a square,
    and then draws a solid square shape using asterisk (*) characters.

    - The input is taken from the user using a function.
    - The square is drawn using nested for loops.
    - The number of rows and columns in the square is equal to the size entered.
    - The program repeats as long as the user chooses to continue.

    Example:
    If user inputs size = 4, the output will be:
    ****
    ****
    ****
    ****
*/

#include <iostream>
#include <limits>
using namespace std;

// Function to get a valid square size from the user
int getSquareSize() {
    int size;

    while (true) {
        cout << "Enter the size of the square (positive integer): ";
        cin >> size;

        if (cin.fail() || size <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a positive whole number.\n";
        } else {
            break;
        }
    }

    return size;
}

// Function to draw a solid square
void drawSquare(int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << "*";
        }
        cout << endl;
    }
}

int main() {
    char choice;

    cout << "==========================================" << endl;
    cout << "  Welcome to the Square Shape Drawer!" << endl;
    cout << "  This program draws a solid square using" << endl;
    cout << "  asterisk (*) characters based on your input." << endl;
    cout << "==========================================" << endl << endl;

    do {
        int squareSize = getSquareSize();
        cout << "\nDrawing a square of size " << squareSize << ":\n" << endl;
        drawSquare(squareSize);

        while (true) {
            cout << "\nWould you like to draw another square? (Y/N): ";
            cin >> choice;

            if (choice == 'Y' || choice == 'y' || choice == 'N' || choice == 'n') {
                cout << endl;
                break;
            } else {
                cout << "Please enter (Y) for yes  or (N) for no.\n";
            }
        }

    } while (choice == 'y' || choice == 'Y');

    cout << "Thank you for using the Square Shape Drawer. Goodbye!" << endl;
    return 0;
}
