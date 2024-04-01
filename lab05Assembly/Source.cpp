#include <iostream>
extern "C" int __fastcall mul2(int);
void main()
{
	std::cout << "Multiply by 2 = " << mul2(5) << std::endl;
}
