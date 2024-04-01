#include <vector>

std::vector<uint16_t> sumNumbers(uint16_t a1, uint16_t a2, uint16_t a3, uint16_t b1, uint16_t b2, uint16_t b3)
	{
		std::vector<uint16_t> res;
		uint16_t c1 = a1 + b1;
		uint16_t c2 = a2 + b2 + (c1 >> 16);
		uint16_t c3 = a3 + b3 + (c2 >> 16);
		uint16_t c4 = a3 >> 16;

		res.emplace_back(static_cast<uint16_t> (c1));
		res.emplace_back(static_cast<uint16_t> (c2));
		res.emplace_back(static_cast<uint16_t> (c3));
		res.emplace_back(static_cast<uint16_t> (c4));

		return res;
	}



std::vector<uint16_t> sumNumbers(uint16_t a1, uint16_t a2, uint16_t a3, uint16_t b1, uint16_t b2, uint16_t b3) {
	std::vector<uint16_t> res;
	uint16_t c1 = 0;
	uint16_t c2 = 0;
	uint16_t c3 = 0;
	uint16_t c4 = 0;

	_asm {
		mov ax, a1
		add ax, b1
		mov c1, ax
		jnc noCarry1
		mov bx,1
		jmp sum2
		noCarry1:mov bx,0
		sum2:
		add bx,a2
        

		mov ax, a2
		adc ax, b2
		mov c2, ax

		mov ax, a3
		adc ax, b3
		mov c3, axr
		mov ax, 0
		add ax, 0
		mov c4, ax
	}

	res.emplace_back(static_cast<uint16_t> (c1));
	res.emplace_back(static_cast<uint16_t> (c2));
	res.emplace_back(static_cast<uint16_t> (c3));
	res.emplace_back(static_cast<uint16_t> (c4));

	return res;
}



