#include <iostream>

int main() {
    int a;
    int res = 0;
    std::cout << "Input a = ";
    std::cin >> a;
    __asm {
        mov eax, a
        imul eax, a //a^2
        imul eax, a //a^3
        imul eax, a //a^4
        imul eax, a //a^5
        mov ebx, a
        imul ebx, a //a^2
        sub ebx, 4 //a^2 - 4
        imul ebx, 2 //2*(a^2 – 4)
        add eax, ebx // a^5 + 2*(a^2 – 4)
        add eax, a // a^5 + 2*(a^2 – 4) + a
        mov ecx, a
        imul ecx, a
        imul ecx, a
        xor edx, edx
        cmp ecx, 0 // Check if a^3 is zero
        je divideByZeroError
        cdq
        idiv ecx // (a^5 + 2*(a^2 – 4) + a) / a^3
        mov res, eax
        jmp finish
        divideByZeroError :
        mov res, -1
            finish:
    }
    std::cout << "Result: " << res;
    return 0;
}

