#include<iostream>

class Integer {
	private:
		int m, n;
	public:
		Integer();
		Integer(int, int);
		Integer(int);
		void show();
};

Integer::Integer() {
	this->m = 0;
	this->n = 0;
}

Integer::Integer(int f) {
	this->m = f;
	this->n = 0;
}

Integer::Integer(int m, int n) {
	this->m = m;
	this->n = n;
}

void Integer::show() {
	std::cout << "\nm: " << this->m << "\nn: " << this->n << "\n";
}

int main() {

	Integer
		i1(0, 100),
		i2 = Integer(100, 75),
		i3,
		i4(10);

	std::cout << "Objeto 1";
	i1.show();

	std::cout << "\nObjeto 2";
	i2.show();

	std::cout << "\nObjeto 3";
	i3.show(); 

	std::cout << "\nObjeto 4";
	i4.show();

	return 0;
}
