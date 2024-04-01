#include "mergeArrays.h"
void mergeArrays(std::vector<int>& arr1, std::vector<int>& arr2, std::vector<int>& result) {
    int _size = arr1.size(); 
    result.resize(_size * 2); 

    int* ptrArr1 = arr1.data();
    int* ptrArr2 = arr2.data();
    int* ptrResult = result.data();

    __asm {
        mov ecx, _size  // ������ ��������
        mov esi, ptrArr1  // ��������� �� ������ ������
        mov edi, ptrArr2  // ��������� �� ������ ������
        mov ebx, ptrResult  // ��������� �� ���������

        // ������������� ��������
        xor eax, eax  // ������ ��� ������� ������� (arr1)
        xor edx, edx  // ������ ��� ������� ������� (arr2)

        merge_loop :
        // ���������� ������� �������� ���� ��������
        mov ebp, [esi + eax * 4]  // ������� ������� �� ������� �������
            mov ecx, [edi + edx * 4]  // ������� ������� �� ������� �������

            // ���������� �������� � ���������� �� � �������������� ������
            cmp ebp, ecx
            jle copy_first  // ���� ������� �� ������� ������� ������ ��� ����� �������� �� ������� �������, �������� ���
            copy_second :  // �������� ������� �� ������� �������
        mov[ebx], ecx
            add ebx, 4
            add edx, 1
            jmp check_end

            copy_first :  // �������� ������� �� ������� �������
        mov[ebx], ebp
            add ebx, 4
            add eax, 1

            check_end :
            cmp eax, ecx
            jl merge_loop  // ���������, �������� �� ����� ������� �������. ���� ���, ���������� �������

            // ���������� ���������� �������� ������� �������
            mov edx, 0  // ���������� ������ ������� �������
            mov ecx, _size  // ��������������� �������� ������� ��������
            mov edi, ptrArr2  // ��������������� ��������� �� ������ ������
            add ebx, [_size * 4]  // �������� ��������� �� ����� ��������������� �������
            merge_remaining:
        mov eax, [edi + edx * 4]  // �������� ���������� ������� �� ������� �������
            mov[ebx], eax
            add ebx, 4
            add edx, 1
            cmp edx, ecx
            jl merge_remaining  // ���������, �������� �� ����� ������� �������
    }
}