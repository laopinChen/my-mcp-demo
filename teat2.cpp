#include <iostream>
using namespace std;

int main() {
    cout << "Program started\n"; // �@���X

    int a;
    cout << "Enter a number: ";
    if (!(cin >> a)) {
        cerr << "Invalid input! Must be a number.\n"; // ���~��X
        return 1;
    }

    cout << "You entered: " << a << endl;
    return 0;
}
