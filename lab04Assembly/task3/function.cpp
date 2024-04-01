#include "function.h"

bool isIntersection(std::vector<int>& arr1, std::vector<int>& arr2, std::vector<int>& arr3) {
    bool isIntersect = false;
    int* a = arr1.data();
    int* b = arr2.data();
    int* c = arr3.data();
    int d = arr1.size();
    int e = arr2.size();
    __asm {
        mov esi, a
        mov edi, b
        mov ecx, d

        mov ebx, c

        xor eax, eax // EAX will act as a flag

        check_intersection :
        mov edx, [esi + eax * 4] // Load element from the first array
            mov edi, b // Reset the pointer to the second array
            mov ebx, e // Reset the counter for the second array size

            check_second_array :
        cmp edx, [edi] // Compare with the current element of the second array
            je intersect_found // If the element is found in both arrays, set the flag and break
            add edi, 4 // Move to the next element of the second array
            loop check_second_array

            next_element :
        add eax, 4 // Move to the next element of the first array
            loop check_intersection

            intersect_found :
        jnz intersection_found
            mov isIntersect, 1 // Set the flag to indicate intersection
            jmp next_element // Continue the loop

            intersection_found :
    }

    return isIntersect;
}

bool isDifference(std::vector<int>& arr1, std::vector<int>& arr2, std::vector<int>& arr3) {
    bool isDiff = true;
    int* a = arr1.data();
    int* b = arr2.data();
    int* c = arr3.data();
    int d = arr1.size();
    int e = arr2.size();
    __asm {
        mov esi, a
        mov edi, b
        mov ecx, d

        mov ebx, c

        xor eax, eax // EAX will act as a flag

        check_difference :
        mov edx, [esi + eax * 4] // Load element from the first array
            mov edi, b // Reset the pointer to the second array
            mov ebx, e // Reset the counter for the second array size

            check_second_array :
        cmp edx, [edi] // Compare with the current element of the second array
            je element_found // If the element is found in both arrays, clear the flag and break
            add edi, 4 // Move to the next element of the second array
            loop check_second_array

            next_element :
        add eax, 4 // Move to the next element of the first array
            loop check_difference

            element_found :
        jnz element_not_found
            mov isDiff, 0 // Clear the flag to indicate difference
            jmp next_element // Continue the loop

            element_not_found :
    }

    return isDiff;
}
