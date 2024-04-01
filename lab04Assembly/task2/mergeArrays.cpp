#include "mergeArrays.h"
void mergeArrays(std::vector<int>& arr1, std::vector<int>& arr2, std::vector<int>& result) {
    int _size = arr1.size(); 
    result.resize(_size * 2); 

    int* ptrArr1 = arr1.data();
    int* ptrArr2 = arr2.data();
    int* ptrResult = result.data();

    __asm {
        mov ecx, _size  // Размер массивов
        mov esi, ptrArr1  // Указатель на первый массив
        mov edi, ptrArr2  // Указатель на второй массив
        mov ebx, ptrResult  // Указатель на результат

        // Инициализация индексов
        xor eax, eax  // Индекс для первого массива (arr1)
        xor edx, edx  // Индекс для второго массива (arr2)

        merge_loop :
        // Сравниваем текущие элементы двух массивов
        mov ebp, [esi + eax * 4]  // Текущий элемент из первого массива
            mov ecx, [edi + edx * 4]  // Текущий элемент из второго массива

            // Сравниваем элементы и записываем их в результирующий массив
            cmp ebp, ecx
            jle copy_first  // Если элемент из первого массива меньше или равен элементу из второго массива, копируем его
            copy_second :  // Копируем элемент из второго массива
        mov[ebx], ecx
            add ebx, 4
            add edx, 1
            jmp check_end

            copy_first :  // Копируем элемент из первого массива
        mov[ebx], ebp
            add ebx, 4
            add eax, 1

            check_end :
            cmp eax, ecx
            jl merge_loop  // Проверяем, достигли ли конца первого массива. Если нет, продолжаем слияние

            // Дописываем оставшиеся элементы второго массива
            mov edx, 0  // Сбрасываем индекс второго массива
            mov ecx, _size  // Восстанавливаем значение размера массивов
            mov edi, ptrArr2  // Восстанавливаем указатель на второй массив
            add ebx, [_size * 4]  // Сдвигаем указатель на конец результирующего массива
            merge_remaining:
        mov eax, [edi + edx * 4]  // Копируем оставшийся элемент из второго массива
            mov[ebx], eax
            add ebx, 4
            add edx, 1
            cmp edx, ecx
            jl merge_remaining  // Проверяем, достигли ли конца второго массива
    }
}