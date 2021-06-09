#include<iostream>

class B {
	private:
		int a;
	public:
		int b;
		void setData(int, int);
		int getA();
};

void B::setData(int a, int b) {
	this->a = a;
	this->b = b;
}

int B::getA() {
	return this->a;
}

class D :public B {
	private:
		int c;
	public:
		void mul();
		void show();
};

void D::mul() {
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

	d.setData(a, b);

	d.mul();
	d.show();

	return 0;


}