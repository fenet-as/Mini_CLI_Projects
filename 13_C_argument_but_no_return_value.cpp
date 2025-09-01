#include <iostream>
using namespace std;

void printSquare(int num) {
    cout << "Square of " << num << " is " << num * num << endl;
}

int main() {
    printSquare(5);  // Call the function with an argument
    return 0;
}