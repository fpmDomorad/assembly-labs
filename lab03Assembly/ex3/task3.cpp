#include <iostream>
#include "degreeFunc.h"

int main() {
    int base, exponent;
    std::cout << "Enter the base: ";
    std::cin >> base;
    std::cout << "Enter the exponent: ";
    std::cin >> exponent;

    int result = degree(base, exponent);
    std::cout << base << " raised to the power of " << exponent << " is " << result << std::endl;

    return 0;
}
