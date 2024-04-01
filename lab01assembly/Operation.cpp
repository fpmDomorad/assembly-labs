#include "Operation.h"
#include "Operation.h"


    int Operation::multiplication(const int& a, const int& b) {
        return a * b;
    }

    int Operation::division(const int& a, const int& b) {
        return a / b;
    }

    int Operation::sum(const int& a, const int& b) {
        return a + b;
    }

    int Operation::subtraction(const int& a, const int& b) {
        return a - b;
    }

    void Operation::move(int& a, int& b) {
        a = b;
    }
