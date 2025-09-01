/*
 ====================================================================
  Population Growth Estimator Program (Repeated Runs)
 --------------------------------------------------------------------
  Description:
    This program estimates the population after a certain number of 
    years based on the starting population, birth rate, and death rate. 
    It uses two functions:

      - GrowthRate: calculates the net population growth rate
      - EstimatedPopulation: calculates the estimated population after n years

    The program validates the user input to ensure no negative birth 
    or death rates and a starting population of at least 2. It repeatedly 
    prompts the user to enter valid inputs, then displays the estimated 
    population after the specified number of years.

    After each estimation, the user is asked if they want to perform another 
    calculation. The program continues until the user enters 'n' or 'N'.

  Features:
    - Calculates population growth rate from birth and death rates
    - Estimates population growth over n years
    - Validates input to prevent invalid values
    - Repeats based on user choice with case-insensitive handling

  Author: [CS section 1, group 5]
  Date: [June 11, 2025]
 ====================================================================
*/

#include <iostream>                     // For input and output
#include <limits>                       // For input validation (numeric_limits)
#include <cmath>                        // For round function
#include <cctype>                      // For tolower()
using namespace std;                    // For standard I/O objects like cin and cout

// Function Prototypes
double GrowthRate(double birthRate, double deathRate);         // Calculates population growth rate
double EstimatedPopulation(double population, double growthRate, int years);  // Estimates population after years

// Main program starts here
int main() {
    char choice;

    // Welcome message
    cout << "==================================================\n";
    cout << "        Population Growth Estimator Program        \n";
    cout << " This program calculates the estimated population  \n";
    cout << " after n years based on the starting population,   \n";
    cout << " birth rate, and death rate you provide.            \n";
    cout << "==================================================\n\n";

    do {
        double population, birthRate, deathRate;
        int years;

        // Input and validation loop for population
        while (true) {
            cout << "Enter starting population (minimum 2): ";
            if (!(cin >> population)) {
                cout << "Invalid input. Please enter a numeric value.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            if (population < 2) {
                cout << "Starting population must be at least 2.\n";
                continue;
            }
            break;
        }

        // Input and validation loop for birth rate
        while (true) {
            cout << "Enter birth rate (non-negative, as a percentage): ";
            if (!(cin >> birthRate)) {
                cout << "Invalid input. Please enter a numeric value.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            if (birthRate < 0) {
                cout << "Birth rate cannot be negative.\n";
                continue;
            }
            break;
        }

        // Input and validation loop for death rate
        while (true) {
            cout << "Enter death rate (non-negative, as a percentage): ";
            if (!(cin >> deathRate)) {
                cout << "Invalid input. Please enter a numeric value.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            if (deathRate < 0) {
                cout << "Death rate cannot be negative.\n";
                continue;
            }
            break;
        }

        // Input and validation loop for years
        while (true) {
            cout << "Enter number of years (non-negative integer): ";
            if (!(cin >> years)) {
                cout << "Invalid input. Please enter an integer value.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            if (years < 0) {
                cout << "Number of years cannot be negative.\n";
                continue;
            }
            break;
        }

        // Calculate growth rate and estimated population
        double rate = GrowthRate(birthRate, deathRate);
        double finalPopulation = EstimatedPopulation(population, rate, years);

        // Display results
        cout << "\nEstimated population after " << years << " years: " << finalPopulation << "\n\n";

        // Ask if user wants to perform another calculation
        do {
            cout << "Do you want to estimate population again? (y/n): ";
            cin >> choice;
            choice = tolower(choice);

            if (choice != 'y' && choice != 'n') {
                cout << "Invalid choice. Please enter 'y' or 'n'.\n";
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
            }
        } while (choice != 'y' && choice != 'n');

        cout << endl;

    } while (choice == 'y');

    cout << "Thank you for using the Population Growth Estimator. Goodbye!" << endl;

    return 0;
}

/* ============================================================================
 Function  : GrowthRate
 Purpose   : Calculate the population growth rate as birth rate minus death rate
 Parameters: double birthRate - birth rate as percentage
             double deathRate - death rate as percentage
 Returns   : double - population growth rate as a percentage
============================================================================ */
double GrowthRate(double birthRate, double deathRate) {
    return birthRate - deathRate;
}

/* ============================================================================
 Function  : EstimatedPopulation
 Purpose   : Calculate estimated population after n years
 Parameters: double population - current population
             double growthRate - population growth rate (percentage)
             int years - number of years to estimate
 Returns   : double - estimated population after n years (rounded)
============================================================================ */
double EstimatedPopulation(double population, double growthRate, int years) {
    for (int i = 0; i < years; ++i) {
        population += (growthRate * population) / 100.0;
    }
    return round(population);
}
