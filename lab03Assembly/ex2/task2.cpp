#include <iostream>
#include <utility>
#include "function1.h" 
int main() {
    int numerator, denominator;
    std::cout << "Enter the numerator: ";
    std::cin >> numerator;
    std::cout << "Enter the denominator: ";
    std::cin >> denominator;

    std::pair<int, int> reducedFraction = reduceFraction(numerator, denominator);
    std::cout << "Reduced fraction: " << reducedFraction.first << "/" << reducedFraction.second << std::endl;

    return 0;
}
