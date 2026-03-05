#include <iostream>
#include <cstddef>

int main() {
    int data[]  = {1,3,6,7,9};
    int data1[] = {5,3,3,3,11};

    for (size_t i = 0; i < std::size(data); ++i) {
        int temp = data[i];
        data[i] = data1[i];
        data1[i] = temp;
    }

    return 0;
}