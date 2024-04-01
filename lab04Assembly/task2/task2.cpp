#include <iostream>
#include <vector>
#include "mergeArrays.h"

std::ostream& operator<<(std::ostream& os, const std::vector<int>& vec) {
    os << "[ ";
    for (const auto& element : vec) {
        os << element << " ";
    }
    os << "]";
    return os;
}

int main() {
    std::vector<int> arr1 = { 1, 3, 5, 7, 9 };
    std::vector<int> arr2 = { 2, 4, 6, 8, 10 };
    std::vector<int> result;

    mergeArrays(arr1, arr2, result);

    std::cout << "Merged array: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << result<<std::endl;

    return 0;
}
