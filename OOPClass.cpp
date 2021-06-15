#include<iostream>

class B {
	private:
		int a;
	public:
		int b;
		void setData();
		int getA();
};

void B::setData() {
	this->a = 15;
	this->b = 20;
}

int B::getA() {
	return this->a;
}

class D :private B {
	private:
		int c;
	public:
		void mul();
		void show();
};

void D::mul() {
	this->setData();
	this->c = b * this->getA();
}

void D::show() {
	std::cout << "A es " << this->getA() << "\nB es " << this->b << "\nC es " <<  this->c << "\n";
}

int main() {
	D d;
	int a, b;

	// Get input
	std::cout << "Ingresar datos: \n";
	std::cout << "Valor A: ";
	std::cin >> a;
	std::cout << "Valor B: ";
	std::cin >> b;

	d.mul();
	d.show();

	return 0;


}