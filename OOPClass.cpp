#include<iostream>

class Bigger {
	private:
		int n1, n2;
		int greater();
	public:
		void ask();
		void show();
};

// Ask the data from the user
void Bigger::ask() {
	std::cout << "Enter 1st num: ";
	std::cin >> this->n1;
	std::cout << "Enter 2nd num: ";
	std::cin >> this->n2;
	std::cout << "\n";
}

// Return the greater number or the sum if they're equals
int Bigger::greater() {
	if (this->n1 == this->n2) {
		return this->n1 + this->n2;
	}
	else if(this->n1 > this->n2){
		return this->n1;
	}

	return this->n2;
}

// Show whose the greater number or if they're equals
void Bigger::show() {

	int greater = this->greater();                      

	if (this->n1 + this->n2 == greater) {
		std::cout << this->n1 << ", " << this->n2 << " son iguales\n\n";
	}
	else {
		std::cout << this->n1 << ", " << this->n2 << " el mayor es " << greater << "\n\n";
	}
}

int main(){

	Bigger bigger;

	// Ask & Display the greater number
	bigger.ask();
	bigger.show();

	system("pause");

	return 0;
}