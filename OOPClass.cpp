#include<iostream>

class Example {
	private:
		int num;
	public:
		static int count;
		void setData(int);
		void showCount();
		void showNum();
};

int Example::count;

void Example::setData(int num) {
	this->num = num;
	this->count++;
}
void Example::showCount() { std::cout << "Cuenta: " << this->count << "\n"; }
void Example::showNum() { std::cout << "Numero: " << this->num << "\n"; }

int main() {
	Example a, b, c;

	a.setData(100);
	a.showNum();
	std::cout << Example::count << "\n";

	b.setData(300);
	b.showNum();
	std::cout << Example::count << "\n";

	c.setData(500);
	c.showNum();
	std::cout << Example::count << "\n";

	return 0;
}
