#include <iostream>

class Product {
	private:
		int id;
		float price;

	public:
		void displayData();
		void setData(); 
		void updatePrice(float); // You can short the parameters
};

void Product::displayData() {
	std::cout << "\nCode: " << this->id;
	std::cout << "\nPrice: $" << this->price << std::endl;
}
void Product::setData() {
	std::cout << "Enter ID: ";
	std::cin >> this->id;
	std::cout << "Enter Price: ";
	std::cin >> this->price;
}

void Product::updatePrice(float price) {
	this->price = price;
}

int main() {

	Product product;
	float price;

	product.setData();
	product.displayData();

	std::cout << "Enter new price: $";
	std::cin >> price;

	product.updatePrice(price);
	product.displayData();

	std::system("pause");

	return 0;
}