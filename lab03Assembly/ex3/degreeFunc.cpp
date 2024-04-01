#include "degreeFunc.h"
#include <iostream>

int degree(int base, int exponent) {
    int result = 1;

    __asm {
        mov eax, base
        mov ecx, exponent
        test ecx, ecx
        jz end
     loop_start :
        test ecx, 1
        jz skip_mul
        imul result
        mov result, eax
     skip_mul :
        imul eax, eax
        shr ecx, 1
        jnz loop_start
        end :
    }

    return result;
}