#include <iostream>

int main() {

    float array[10];

    for (int i = 0; i < 10; i++) {
        array[i] = 0;
    }

    for (int i = 0; i < 10; i++) {
        std::cout << &array[i] << " ";
    }

    return 0;
}

