#include "PowersOfTwo.h"
#include <utility>
#include <iostream>

std::pair<int, int> PowersOfTwo(int number) {
    int lowerPower = 0;
    int upperPower = 0;

    __asm {
        mov eax, number      // �������� ����� � eax
        xor ebx, ebx         // �������� ebx
     loop_start :
        test eax, eax        // ���������, ����� �� ��������� 0
        jz end               // ���� ��������� ����� 0, ��������� ���������          inc ebx              // ����������� ������� �������� ������
        mov ecx, eax         // �������� ����� � ecx
        shr ecx, 1           // �������� ����� �� 1 ������ (��������� ��� �� ������� ������)
        cmp ecx, 1           // ���������� ��������� � 1
        jne loop_start       // ���� ��������� �� ����� 1, ���������� ����
        mov lowerPower, ebx  // �������� ������� �������� ������ � lowerPower
        dec ebx              // ��������� ������� �������� ������ �� 1
        mov upperPower, ebx  // �������� ������� �������� ������ � upperPower
     end :
    }

    return std::make_pair(lowerPower, upperPower);
}