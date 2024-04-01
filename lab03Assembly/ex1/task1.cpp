#include <iostream>
#include "function.h"

int main()
{
    int inputNumber;
    std::cout << "Enter an integer:";
    std::cin >> inputNumber;

    std::pair<int, int> result = evenAndZeroNumbersCounter(inputNumber);

    std::cout << "Number of even digits: " << result.first << std::endl;
    std::cout << "Number of zero digits: " << result.second << std::endl;

    return 0;
}
