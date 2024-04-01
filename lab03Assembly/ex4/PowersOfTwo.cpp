#include "PowersOfTwo.h"
#include <utility>
#include <iostream>

std::pair<int, int> PowersOfTwo(int number) {
    int lowerPower = 0;
    int upperPower = 0;

    __asm {
        mov eax, number      // Помещаем число в eax
        xor ebx, ebx         // Обнуляем ebx
     loop_start :
        test eax, eax        // Проверяем, равен ли результат 0
        jz end               // Если результат равен 0, завершаем программу          inc ebx              // Увеличиваем счетчик степеней двойки
        mov ecx, eax         // Помещаем число в ecx
        shr ecx, 1           // Сдвигаем число на 1 вправо (уменьшаем его на степень двойки)
        cmp ecx, 1           // Сравниваем результат с 1
        jne loop_start       // Если результат не равен 1, продолжаем цикл
        mov lowerPower, ebx  // Помещаем счетчик степеней двойки в lowerPower
        dec ebx              // Уменьшаем счетчик степеней двойки на 1
        mov upperPower, ebx  // Помещаем счетчик степеней двойки в upperPower
     end :
    }

    return std::make_pair(lowerPower, upperPower);
}