#include <iostream>

int main() {
	int a;
	std::cout << "Input a = ";
	std::cin >> a;
    if (a == 1) {
        throw;
    }
    int n;
    int counter = 0;
    __asm {
        mov eax, a
        mov ecx, counter
        cycle :
        inc ecx
            imul eax, a
            jno cycle
            mov n, ecx
    }
	std::cout << "Res " << n<<"\n";
	return 0;
}
