#include <iostream>
#include "PowersOfTwo.h"

int main() {
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;

    std::pair<int, int> powers = PowersOfTwo(number);
    std::cout << "The number " << number << " is between 2^" << powers.first << " and 2^" << (powers.second+1) << std::endl;

    return 0;
}
