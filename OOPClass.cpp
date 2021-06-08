#include<iostream>

class B;

class A {
	private:
		int value;
	public:
		void setValue(int);
		void show();
		friend int sum(A, B);
};

void A::setValue(int value) { this->value = value; }
void A::show() { std::cout << "El valor de A es: " << this->value << "\n"; }

class B {
private:
	int value;
public:
	void setValue(int);
	void show();
	friend int sum(A, B);
};

void B::setValue(int value) { this->value = value; }
void B::show() { std::cout << "El valor de B es: " << this->value << "\n"; }

// Friend Functions
int sum(A a, B b) {
	return a.value + b.value;
}

int main() {
	A a;
	B b;
	int value;

	// Get Values
	std::cout << "Ingresa el valor de A: ";
	std::cin >> value;
	a.setValue(value);
	               
	std::cout << "Ingresa el valor de B: ";
	std::cin >> value;
	b.setValue(value);

	value = sum(a, b);

	std::cout << "La suma de A y B es: " << value << "\n";

	system("pause");

	return 0;
}