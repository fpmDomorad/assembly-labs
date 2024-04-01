#include <iostream>
int main(){
int a,res;
std::cout << "Input a = ";
std::cin >> a;
__asm{
	mov  ecx,a
	mov  eax, ecx
	imul eax,eax
	imul eax,ecx
	mov  ebx, eax//a^3
	imul eax,ecx
	imul eax, ecx //a^5
	add eax,ebx//a^5+a^3
	add eax,ecx//a^5+a^3+a
	mov res,eax
}
std::cout << "Res: " << res << std::endl;
}