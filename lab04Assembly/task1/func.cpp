#include "func.h"

void quantityOfDiffValues(int* _ptr)
{

	int i = 0;
	//int j = *_ptr - 1;
	int _length = *_ptr;


	/*__asm {
		mov eax, length
		mov ebx, i
		mov ecx, j
		mov edx, k
	__firstLoop :
		cmp ebx, eax
			jnl __end
	__secondLoop:
		cmp ecx, ebx
		jng	__firstLoop
		cmp [ptr + ebx], [ptr + ecx]
		je __thirdLoop
		dec ecx
		jmp __secondLoop
	__thirdLoop:
		cmp edx, eax - 1
		jl __ptrWork
		dec eax
		jmp __secondLoop
	__ptrWork:
		mov [ptr + edx], [ptr + edx + 1]
		inc edx
		jmp __thirdLoop
	__end:

}*/


	__asm {
		mov edx, dword ptr[_ptr]
		mov eax, dword ptr[edx]
		mov esi, 1
		firstLoopBegin_ :
		cmp esi, dword ptr[edx]
			jl secondLoop_
			jmp end__
			secondLoop_ :
		mov edi, dword ptr[edx]
			secondLoopBegin_ :
			cmp edi, esi
			jg continueSecondLoop_
			inc esi
			jmp firstLoopBegin_
			continueSecondLoop_ :
		mov ebx, dword ptr[edx + esi * 4]
			cmp ebx, dword ptr[edx + edi * 4]
			je thirdLoop_
			dec edi
			jmp secondLoopBegin_

			thirdLoop_ :

		mov ecx, dword ptr[edx]
			sub ecx, edi
			mov i, esi
			mov esi, edi

			thirdLoopBegin_ :

		mov eax, dword ptr[edx + esi * 4]
			mov ebx, [edx + esi * 4 + 4]
			mov[edx + esi * 4], ebx

			dec dword ptr[edx]
			loop thirdLoopBegin_
			mov esi, i

			jmp secondLoopBegin_
			end__ :
	}

}
