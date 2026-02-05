#include <iostream>
#include <string>

using namespace std;

string intToBinary(int num) {
    if (num == 0) return "0";

    string binary = "";
    while (num > 0) {
        binary = char('0' + (num % 2)) + binary;
        num /= 2;
    }
    return binary;
}

string charToBinary(char c) {
    string binary = "";
    int value =  int(c);
    for (int i = 7; i >= 0; --i) {
        binary += ((value >> i) & 1) ? '1' : '0';
    }
    return binary;
}

string floatToBinary(float f) {
    int intergerPart = int(num);
    float fractionalPart = num - intergerPart;
    string binary = intToBinary(intergerPart) + ".";
    binary += ".";

    for (int i = 0; i < 6; ++i) {
        fractionalPart *= 2;
        int bit = int(fractionalPart);
        if (bit == 1) {
            binary += "1";
            fractionalPart -= bit;
        } else {
            binary += "0";
        }
    }
    int main() {
        char c='A';
        int i =10;
        float f = 10.625;
        cout << "Binary of char " << c << " is: " << charToBinary(c) << endl;
        cout << "Binary of int " << i << " is: " << intToBinary(i) << endl;
        cout << "Binary of float " << f << " is: " << floatToBinary(f) << endl;

        return 0;
}
