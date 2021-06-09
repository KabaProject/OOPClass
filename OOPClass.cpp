#include<iostream>

class Fraction {
	private:
		int num, den;
	public:
		Fraction() : num(0), den(0) {};
		Fraction(int value) : num(value), den(value) {};
		Fraction(int num, int den) : num(num), den(den) {};
		void show();
		friend Fraction sum(Fraction, Fraction);
};
 
void Fraction::show() {
	std::cout << "La fraccion es: " << this->num << "/" << this->den << "\n";
}

Fraction sum(Fraction a, Fraction b) {
	int num = a.num * b.den + b.num * a.den;
	int den = a.den * b.den;

	return Fraction(num, den);
};

int main() {

	Fraction fract_a, fract_b, fract_c;
	int num, den;

	// Get the input
	std::cout << "Ingrese 1era Fraccion:\n";
	std::cout << "Numerador: ";
	std::cin >> num;
	std::cout << "Denominador: ";
	std::cin >> den;

	fract_a = Fraction(num, den);

	std::cout << "\nIngrese 2da Fraccion:\n";
	std::cout << "Numerador: ";
	std::cin >> num;
	std::cout << "Denominador: ";
	std::cin >> den;

	fract_b = Fraction(num, den);

	fract_c = sum(fract_a, fract_b);
	fract_c.show();

	system("pause");

	return 0;
}