#ifndef OPERATION_H
#define OPERATION_H

#include <iostream>



class Operation {
public:

    Operation() = default;
    ~Operation() = default;

    static int multiplication(const int& a, const int& b);

    static int division(const int& a, const int& b);

    static int sum(const int& a, const int& b);

    static int subtraction(const int& a, const int& b);

    static void move(int& a, int& b);

private:
};

#endif //OPERATION_H
