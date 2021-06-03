#include<iostream>

class Test{
	private:
		int code;
		static int count;
	public:
		void setCode();
		void showCode();
		void showCount();
};

void Test::setCode() { this->code = this->count };
void Test::showCode() { std::cout << "Codigo: " << this->code << "\n"; };
void Test::showCount() { std::cout << "Cuenta: " << this->count << "\n"; };