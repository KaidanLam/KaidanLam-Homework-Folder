#include <iostream>

void printCommonUnique(const int a[], int na, const int b[], int nb) {
    for (int i = 0; i < na; ++i) {

        // Check if a[i] exists in b
        bool inB = false;
        for (int j = 0; j < nb; ++j) {
            if (a[i] == b[j]) {
                inB = true;
                break;
            }
        }
        if (!inB) continue;

        // Prevent printing duplicates from a (no extra array used)
        bool alreadyPrinted = false;
        for (int k = 0; k < i; ++k) {
            if (a[k] == a[i]) {
                alreadyPrinted = true;
                break;
            }
        }
        if (alreadyPrinted) continue;

        std::cout << a[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    int data[]  = {1, 3, 6, 7, 9};
    int data1[] = {5, 3, 3, 3, 11};

    int n0 = sizeof(data) / sizeof(data[0]);
    int n1 = sizeof(data1) / sizeof(data1[0]);

    printCommonUnique(data, n0, data1, n1); // expected output: 3
    return 0;
}