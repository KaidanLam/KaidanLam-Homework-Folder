#include <iostream>

int main() {
    int data[]  = {1,3,6,7,9};
    int data1[] = {5,3,3,11,15};   

    const int n0 = sizeof(data)  / sizeof(data[0]);
    const int n1 = sizeof(data1) / sizeof(data1[0]);

    if (n0 != n1) {
        std::cout << "Cannot swap: arrays are different sizes (" << n0 << " vs " << n1 << ")\n";
        return 0;
    }

    for (int i = 0; i < n0; ++i) {
        int temp = data[i];
        data[i] = data1[i];
        data1[i] = temp;
    }

    // show result
    std::cout << "data:  ";
    for (int i = 0; i < n0; ++i) std::cout << data[i] << " ";
    std::cout << "\ndata1: ";
    for (int i = 0; i < n1; ++i) std::cout << data1[i] << " ";
    std::cout << "\n";
}