#include "function.h"
#include <iostream>
#include <utility>

std::pair <int, int> evenAndZeroNumbersCounter(int num)
{
	uint8_t evenAmount = 0; //ch
	uint8_t zeroAmount = 0; //cl
	_asm{ 
        xor ch, ch
        xor cl, cl
        mov ebx, 10
        mov eax, num
        cmp eax, 0
        je zeroEq
        jl _abs
        jmp _loop
        _abs :
        neg eax
            _loop :
        cmp eax, 0
            jz finish
            cdq
            idiv ebx
            test edx, 1 //0b00000001
            jnz _loop //ignoring odd number
            inc ch
            cmp edx, 0 //if digit is 0
            jnz _loop
            inc cl
            jmp _loop
            finish :
        mov evenAmount, ch
            mov zeroAmount, cl
            jmp end_
            zeroEq :
        mov evenAmount, 1
            mov zeroAmount, 1
            end_ :
    }
    std::pair <int, int> result(zeroAmount, evenAmount);
    return result;
}
