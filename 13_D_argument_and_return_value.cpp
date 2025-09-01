#include <iostream>
using namespace std;

int add(int a, int b) {
    return a + b;  // Return the sum of the two arguments

}

int main() {
    int sum = add(10, 20);  // Call the function with arguments and get return value
    cout << "Sum is: " << sum << endl;
    return 0;
}
