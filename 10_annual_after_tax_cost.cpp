/*
 * Program: Annual After-Tax Cost Calculator for New Homeowners
 * Language: C++
 * Author: [CS secttion 1, group 5]
 * Date: [June 7,2025]
 *
 * This program calculates the annual after-tax cost of a mortgage for a new homeowner.
 * It takes the following inputs from the user:
 *  - Currency label (e.g., USD, ETB, GBP)
 *  - Price of the house (must be between 100,000 and 1,000,000,000 units of the specified currency)
 *  - Down payment amount (must be non-negative and less than the house price)
 *
 * Using these inputs, the program computes:
 *  - Loan amount (house price minus down payment)
 *  - Annual mortgage cost, calculated as the sum of principal (3%) and interest (8%) on the loan amount
 *  - Tax savings, based on a 35% tax credit on the interest portion of the mortgage cost
 *  - Final after-tax cost of the mortgage (mortgage cost minus tax savings)
 *
 * The program outputs a summary of all these values formatted to two decimal places.
 * It also allows the user to perform multiple calculations in a single run.
 *
 * Note:
 *  - Input validation is included to ensure realistic and logical values.
 *  - The user can choose to calculate again or exit the program.
 * 
 */

#include <iostream>
#include <iomanip> // for formatting output
#include <limits>  // for numeric_limits

using namespace std;

// Function to calculate annual mortgage cost (principal + interest)
double calculateMortgageCost(double loanAmount) {
    return loanAmount * 0.03 + loanAmount * 0.08;
}

// Function to calculate tax savings (35% of interest)
double calculateTaxSavings(double loanAmount) {
    return (loanAmount * 0.08) * 0.35;
}

int main() {
    double price, downPayment, loanAmount;
    double mortgageCost, taxSavings, afterTaxCost;
    string currency;
    char again;

    // Descriptive welcome message
    cout << "Welcome to the Annual After-Tax Cost Calculator for New Homeowners!\n";
    cout << "This program helps you understand the yearly cost of your mortgage after accounting for tax savings.\n";
    cout << "You will be asked to enter the currency, house price, and your down payment.\n";
    cout << "Let's get started!\n\n";

    cout << " Annual After-Tax Cost Calculator for New Homeowners\n";
    cout << "-------------------------------------------------------\n";

    do {
        // Ask the user to enter currency (symbol or name)
        cout << "\nEnter currency label (e.g. USD, ETB, GBP): ";
        cin >> currency;

        // Input and validate house price with loop
        while (true) {
            cout << "Enter the price of the house: ";
            cin >> price;

            if (cin.fail()) {
                cin.clear(); // clear error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
                cout << "Error: Please enter a valid numeric value for price.\n";}

            else if (price >= 100000 && price <= 1000000000) {
                break;  // valid price, exit loop
            } else {
                cout << "Error: Please enter a price between 100,000 and 1,000,000,000 " << currency << ".\n";
            }
        }

        // Input and validate down payment with loop (including non-numeric check)
        while (true) {
            cout << "Enter the down payment: ";
            cin >> downPayment;

            if (cin.fail()) {
                cin.clear(); // clear error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
                cout << "Error: Please enter a valid numeric value for down payment.\n";
            } else if (downPayment >= 0 && downPayment < price) {
                break;  // valid input
            } else {
                cout << "Error: Down payment must be between 0 and less than the price of the house.\n";
            }
        }

        // Calculate initial loan balance
        loanAmount = price - downPayment;

        // Mortgage cost (principal + interest)
        mortgageCost = calculateMortgageCost(loanAmount);

        // Tax savings (35% of the interest portion)
        taxSavings = calculateTaxSavings(loanAmount);

        // Final after-tax cost
        afterTaxCost = mortgageCost - taxSavings;

        // Format output to 2 decimal places
        cout << fixed << setprecision(2);

        // Display results
        cout << "\n --- Calculation Summary ---\n";
        cout << "House Price           : " << price << " " << currency << "\n";
        cout << "Down Payment          : " << downPayment << " " << currency << "\n";
        cout << "Loan Amount           : " << loanAmount << " " << currency << "\n";
        cout << "Annual Mortgage Cost  : " << mortgageCost << " " << currency << "\n";
        cout << "Tax Savings (35%)     : " << taxSavings << " " << currency << "\n";
        cout << "After-Tax Cost        : " << afterTaxCost << " " << currency << "\n";

        // Ask if user wants to calculate again
        cout << "\nWould you like to calculate again? (Y/N): ";
        cin >> again;

        // Input validation (accept lowercase or uppercase Y/N)
        while (again != 'Y' && again != 'y' && again != 'N' && again != 'n') {
            cout << " Invalid input. Please enter Y (yes) or N (no): ";
            cin >> again;
        }

    } while (again == 'Y' || again == 'y');

    cout << "\n Thank you for using the calculator. Stay financially smart!\n";
    return 0;
}
