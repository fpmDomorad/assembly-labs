#include <iostream>
#include <vector>
#include "function.h"

int main() {
    std::vector<int> arr1 = { 1, 2, 3, 4, 5 };
    std::vector<int> arr2 = { 4, 5, 6, 7, 8 };
    std::vector<int> arr3 = { 4, 5 };

    if (isIntersection(arr1, arr2, arr3)) {
        std::cout << "The third array is an intersection of the first two arrays." << std::endl;
    }
    else {
        std::cout << "The third array is not an intersection of the first two arrays." << std::endl;
    }

    if (isDifference(arr1, arr2, arr3)) {
        std::cout << "The third array is a difference of the first two arrays." << std::endl;
    }
    else {
        std::cout << "The third array is not a difference of the first two arrays." << std::endl;
    }

    return 0;
}
