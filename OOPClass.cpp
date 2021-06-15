#include<iostream>
#include<iomanip>

class Student {
	protected:
		int num_list;
		Student(): num_list(0) {};
		Student(int num_list) : num_list(num_list) {};
};

class Test :protected Student {
	private:
		float cals[2];
	protected:
		Test(): cals { 0, 0 }{};
		Test(int, float cals[2][3]);
		float getAvg();
		float getFirstCal();
		int getNumList();
};

Test::Test(int num_list, float cals[2][3]) :Student(num_list) {
	this->cals[0] = (cals[0][0] + cals[0][1] + cals[0][2]) / 3;
	this->cals[1] = (cals[1][0] + cals[1][1] + cals[1][2]) / 3;
}

float Test::getAvg() {
	return (cals[0] + cals[1]) / 2;
}

float Test::getFirstCal() {
	return this->cals[0];
}

int Test::getNumList() {
	return this->num_list;
}

class Result :private Test {
	private:
		float total;
	public:
		Result(): total(0) {};
		Result(int, float cals[2][3]);
		static int count;
		static void firstFail(Result*);
		friend void fail(Result*);
};

int Result::count = 0;

Result::Result(int num_list, float cals[2][3]) :Test(num_list, cals) {
	this->total = this->getAvg();
}

void Result::firstFail(Result* results) {
	for (int i = 0; i < Result::count; i++) {
		if (results[i].getFirstCal() < 6) {
			std::cout << std::setw(15) << results[i].num_list << std::setw(15) << results[i].getFirstCal() << "\n";
		}
	}
}

void fail(Result* results) {
	for (int i = 0; i < Result::count; i++) {
		if (results[i].total < 6) {
			std::cout << std::setw(15) << results[i].num_list << std::setw(15) << results[i].total << "\n";
		}
	}
}

int main() {

	Result results[10];

	int opt, num_list;
	float cals[2][3];
	char cmd = 'n';

	do
	{

		std::cout << "===== Escuela Kiroshima =====\n";
		std::cout << "\n\t1)Registrar Alumno\n\t2)Alumnos Reprobados 1er Parcial\n\t3)Alumnos Reprobados 1er Parcial\n\t4)Salir\n";
		std::cin >> opt;

		system("cls");

		switch (opt)
		{
			case 1:
				std::cout << "Registre los datos\n";
				std::cout << "Numero de Lista: ";
				std::cin >> num_list;

				std::cout << "1er Parcial\n";
				for (int i = 0; i < 3; i++) {
					std::cout << "Cal " << i + 1 << ": ";
					std::cin >> cals[0][i];
				}

				std::cout << "2do Parcial\n";
				for (int i = 0; i < 3; i++) {
					std::cout << "Cal " << i + 1 << ": ";
					std::cin >> cals[1][i];
				}

				results[Result::count] = Result(num_list, cals);
				Result::count++;
				
				break;
			case 2:
				std::cout << std::setw(15) << "Numero de Lista" << std::setw(15) << "Calificacion\n";
				Result::firstFail(results);
				break;
			case 3:
				std::cout << std::setw(15) << "Numero de Lista" << std::setw(15) << "Calificacion\n";
				fail(results);
				break;
		}
		if (opt != 4) {
			std::cout << "\n\nQuieres hacer otra accion? [y/n]: ";
			std::cin >> cmd;
		}

		system("cls");

	} while (opt != 4 && cmd != 'N' && cmd != 'n');

	std::cout << "GRACIAS POR SU TIEMPO 8)\n";
	system("pause");

	return 0;
}