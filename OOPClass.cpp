#include<iostream>

int main() {

	int num[] = { 56, 75, 22, 18, 90 };
	int* ptr = num;

	std::cout << "Valor de ptr: " << *ptr << std::endl;
	ptr++;
	std::cout << "Valor de ptr++: " << *ptr << std::endl;
	ptr--;
	std::cout << "Valor de ptr--: " << *ptr << std::endl;
	ptr += 2;
	std::cout << "Valor de ptr+2: " << *ptr << std::endl;
	ptr -= 1;
	std::cout << "Valor de ptr-1: " << *ptr << std::endl;
	ptr += 3;
	std::cout << "Valor de ptr+3: " << *ptr << std::endl;
	ptr -= 2;
	std::cout << "Valor de ptr-2: " << *ptr << std::endl;

	return 0;
}