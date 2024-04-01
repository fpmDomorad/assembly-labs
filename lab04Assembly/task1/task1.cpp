#include <iostream>
#include <vector>

#include "func.h"


int main() {

	int size;
	std::cout << "Input the size of the array: ";
	std::cin >> size;

	std::vector <int> vec;
	vec.reserve(size + 1);

	int tmp;

	for (size_t i = 1; i < size + 1; ++i) {
		std::cin >> tmp;
		vec.push_back(tmp);
	}

	int* ptrArr = vec.data();
	int* length = ptrArr;
	*length = size; //vec[0] = size;

	/*
	std::vector <int> vec = {5, 1, 1, 2, 2, 3};

	int size = 5;

	int* ptrArr = vec.data();
	int* length = ptrArr;
	*length = size; //vec[0] = size;

	size_t i = 1;

  while (i < *length) {
	size_t j = *length;
	while (j > i) {
		if ((*(length + i)) == (*(length + j))) {
			for (int k = j; k < *length; ++k) {
				*(length + k) = *(length + k + 1);
			}
			*length = *length - 1;

		}
		--j;
	}
	++i;
}
	for (size_t i = 0; i <= vec[0]; ++i){
		std::cout << vec[i] << ' ';
	}
	*/

	quantityOfDiffValues(length);

	std::cout << "Rebuild vector looks like:\n";

	for (size_t i = 1; i <= vec[0]; ++i) {
		std::cout << vec[i] << ' ';
	}
	std::cout << '\n';

	std::cout << "Vector's size is " << vec[0] << '\n';

}