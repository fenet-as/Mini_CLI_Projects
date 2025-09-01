#include <iostream>
using namespace std;

int getUserAge() {
    int age;
    cout << "Enter your age: ";
    cin >> age;
    return age;
}

int main() {
    int userAge = getUserAge();
    cout << "Your age is: " << userAge << endl;
    return 0;
}