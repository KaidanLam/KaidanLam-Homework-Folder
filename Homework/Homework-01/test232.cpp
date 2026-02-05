#include <iostream>
#include <bitset>
#include <cstring>

using namespace std;

// Function to convert char to binary
void charToBinary(char c) {
    bitset<8> b(c);
    cout << "Binary (char): " << b << endl;
}

// Function to convert int to binary
void intToBinary(int n) {
    bitset<32> b(n);
    cout << "Binary (int): " << b << endl;
}

// Function to convert float to binary
void floatToBinary(float f) {
    int bits;
    memcpy(&bits, &f, sizeof(float));
    bitset<32> b(bits);
    cout << "Binary (float): " << b << endl;
}

int main() {
    int choice;
    cout << "Choose input type:\n";
    cout << "1. Character\n";
    cout << "2. Integer\n";
    cout << "3. Float\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1) {
        char c;
        cout << "Enter a character: ";
        cin >> c;
        charToBinary(c);
    }
    else if (choice == 2) {
        int n;
        cout << "Enter an integer: ";
        cin >> n;
        intToBinary(n);
    }
    else if (choice == 3) {
        float f;
        cout << "Enter a float: ";
        cin >> f;
        floatToBinary(f);
    }
    else {
        cout << "Invalid choice" << endl;
    }

    return 0;
}
