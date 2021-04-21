// Class-19-04-21.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>

struct Address {
    std::string street;
    int number;
};

struct Employee {
    char name[10];
    int age;
    Address address;
};

Employee getEmployeeInput() {
    Employee employee;

    std::cout << "Ingresa el nombre: ";
    std::cin >> employee.name;

    std::cout << "Ingresa la edad: ";
    std::cin >> employee.age;

    std::cout << "Ingresa la direccion" << std::endl;
    std::cout << "Calle: ";
    std::cin >> employee.address.street;
    std::cout << "Numero: ";
    std::cin >> employee.address.number;

    return employee;
}

float getAvgEmployeeAge(Employee employees[]) {
    int arrLen = sizeof(*employees) / sizeof(employees[0]);
    float avgAge = 0;

    for (int i = 0; i < arrLen; i++) {
        avgAge += employees[i].age;
    }

    avgAge /= arrLen;
    return avgAge;
}

void printOldestEmployee(Employee employees[]) {
    int arrLen = sizeof(*employees) / sizeof(employees[0]);
    Employee oldestEmployee{ "", 0, {"", 0} };

    for (int i = 0; i < arrLen; i++) {
        if (oldestEmployee.age < employees[i].age) {
            oldestEmployee = employees[i];
        }
    }

    std::cout << "El empleado mas viejo es " << oldestEmployee.name << " con " << oldestEmployee.age << " anios" << std::endl;
}

void printEmployeeData(Employee employee) {
    std::cout << "Nombre:     " << employee.name << std::endl;
}


int main()
{
    Employee employees[2];
    float avgAge;

    for (int i = 0; i < 2; i++) {
        std::cout << "======= Empleado #" << i << " =======" << std::endl;
        employees[i] = getEmployeeInput();
        std::cout << std::endl;
    }

    avgAge = getAvgEmployeeAge(employees);
    std::cout << "La edad promedio es de " << avgAge << " anios" << std::endl;

    printOldestEmployee(employees);

    //std::cout << "====== Empleados ======" << std::endl;
    //for (int i = 0; i < 2; i++) {
    //    printEmployeeData(employees[i]);
    //    if (i < 1) std::cout << std::endl;
    //}
    //std::cout << "=======================" << std::endl;

    system("pause");
    return 0;
}


