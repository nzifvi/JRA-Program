#include "Headers/DynamicArray.h"
#include <iostream>

int main() {
    DynamicArray<int> array;
    for (int i = 0; i < 10; i++) {
        array.insert(0, 1);
    }

    std::cout << array << "\n";

    array.insert(1, 100);

    std::cout << array << "\n";

}