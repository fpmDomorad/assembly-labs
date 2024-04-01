#include "function1.h"

std::pair<int, int> reduceFraction(int numerator, int denominator) {
    int gcd = 0;

    // Calculate GCD
    __asm {
        xor eax, eax
        mov ebx, numerator
        mov ecx, denominator
        test ebx, ebx
        jns positive_numerator
        neg ebx
        positive_numerator :
        test ecx, ecx
            jns positive_denominator
            neg ecx
            positive_denominator :
        cmp ebx, ecx
            jne compare
            mov gcd, ebx
            jmp end
            compare :
        jb swap
            sub ebx, ecx
            jmp positive_numerator
            swap :
        xchg ebx, ecx
            jmp positive_numerator
            end :
    }

    // Reduce the fraction
    numerator /= gcd;
    denominator /= gcd;

    return std::make_pair(numerator, denominator);
}