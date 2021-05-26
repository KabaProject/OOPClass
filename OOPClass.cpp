#include<iostream>

class Example {
	private:
		int data;
		
		void read();
		void write();

	public:
		void show();
};

void Example::read() {
	std::cout << "Enter the data: ";
	std::cin >> this->data;
}

void Example::write() {
	std::cout << this->data;
}

void Example::show() {
	this->read();
	this->write();
}

int main() {

	Example example;

	example.show();

	return 0;
}