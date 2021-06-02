#include<iostream>
#include<iomanip>

const int SIZE = 50;

class Product {
	private:
		int codes[SIZE];
		float prices[SIZE];
		int count = 0;

	public:
		void
			cnt(),
			show(),
			add(int, float),
			showByCode();
		float
			sum();
};

void Product::cnt() { std::cout << this->count << " articulo(s)\n"; };
void Product::add(int code, float price) {
	this->codes[this->count] = code;
	this->prices[this->count] = price;
	this->count++;

	std::cout << "¡Articulo añadido!\n";
}
void Product::show() {
	std::cout << std::setw(10) << "Codigos" << std::setw(10) << "Precios\n";
	for (int i = 0; i < this->count; i++) {
		std::cout << std::setw(10) << this->codes[i] << std::setw(10) << std::setprecision(2) << this->prices[i] << "\n";
	}
}

void Product::showByCode() {
	int code, idx = -1;

	std::cout << "Codigo: #";
	std::cin >> code;

	for (int i = 0; i < this->count; i++) {
		if (this->codes[i] == code) {
			idx = i;
		}
	}

	if (idx == -1) {
		std::cout << "Articulo no encontrado\n";
	}
	else {
		std::cout << "Articulo #" << this->codes[idx] << " tiene un costo de $" << this->prices[idx] << "\n";
	}
}

float Product::sum() {
	float total = 0;

	if (this->count == 0) {
		return 0;
	}

	for (int i = 0; i < this->count; i++) {
		total = total + this->prices[i];
	}

	return total;
}

int main() {

	Product product;
	int opt;
	char command;

	do {
		std::cout << "TIENDA DE AUTOSERVICIO \"MANDADITO\"\n" << "\n"
			<< "\t1) Ver Numero de Articulos\n"
			<< "\t2) Mostrar Articulos\n"
			<< "\t3) Añadir Articulo\n"
			<< "\t4) Ver Costo Total\n"
			<< "\t5) Buscar Articulo\n"
			<< "\t6) Salir\n"
			<< "\n"
			<< "Ingrese una opcion: ";
		std::cin >> opt;

		system("cls");

		switch (opt) {
			case 1:
				product.cnt();
				break;
			case 2:
				product.show();
				break;
			case 3:
				int code;
				float price;
				std::cout << "Ingresa el Codigo: #";
				std::cin >> code;
				std::cout << "Ingrese el Precio: $";
				std::cin >> price;
				product.add(code, price);
				break;
			case 4:
				std::cout << "Costo total: $" << product.sum() << "\n";
				break;
			case 5:
				product.showByCode();
				break;
		}

		std::cout << "¿Quieres hacer otra operación? [Y/N]";
		std::cin >> command;
		system("cls");

	} while (opt != 6 || command == 'n' || command == 'N');


	std::cout << "\nGRACIAS POR SU SESIÓN, ¡HASTA LUEGO!\n";

	system("pause");

	return 0;
}