#include <iostream>
using namespace std;

int main() {
    int count = 10;   // Initialize count to 10
    int sum = 0;      // Initialize sum to 0

    // Loop variable i starts at 10, runs while i >= 0
    for (int i = count; i >= 0; sum += i--) {
        // Empty loop body: all work happens in the update expression sum += i--
        // Explanation per iteration:

        // 1st iteration: i = 10
        // sum += i-- adds 10 to sum (sum = 0 + 10 = 10), then i becomes 9

        // 2nd iteration: i = 9
        // sum += i-- adds 9 to sum (sum = 10 + 9 = 19), then i becomes 8

        // 3rd iteration: i = 8
        // sum += i-- adds 8 to sum (sum = 19 + 8 = 27), then i becomes 7

        // 4th iteration: i = 7
        // sum += i-- adds 7 to sum (sum = 27 + 7 = 34), then i becomes 6

        // 5th iteration: i = 6
        // sum += i-- adds 6 to sum (sum = 34 + 6 = 40), then i becomes 5

        // 6th iteration: i = 5
        // sum += i-- adds 5 to sum (sum = 40 + 5 = 45), then i becomes 4

        // 7th iteration: i = 4
        // sum += i-- adds 4 to sum (sum = 45 + 4 = 49), then i becomes 3

        // 8th iteration: i = 3
        // sum += i-- adds 3 to sum (sum = 49 + 3 = 52), then i becomes 2

        // 9th iteration: i = 2
        // sum += i-- adds 2 to sum (sum = 52 + 2 = 54), then i becomes 1

        // 10th iteration: i = 1
        // sum += i-- adds 1 to sum (sum = 54 + 1 = 55), then i becomes 0

        // 11th iteration: i = 0
        // sum += i-- adds 0 to sum (sum = 55 + 0 = 55), then i becomes -1

        // After this iteration, the condition i >= 0 fails (i = -1),
        // so the loop stops.
    }

    cout << sum;  // Prints 55

    return 0;
}
