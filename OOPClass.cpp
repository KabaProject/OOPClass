// Class-19-04-21.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <time.h>

struct Date {
    int day, month, year;
};

struct Employee {
    int id;
    char name[10];
    Date date;
    float salary[3];
};

Employee getEmployeeInput() {
    Employee employee;
    Date date;

    std::cout << "Ingresa el id: ";
    std::cin >> employee.id;

    std::cout << "Ingresa el nombre: ";
    std::cin >> employee.name;

    //std::cout << "\nIngresa fecha del registro" << std::endl;
    //std::cout << "Ingresa Dia: ";
    //std::cin >> date.day;
    //std::cout << "Ingresa Mes: ";
    //std::cin >> date.month;
    //std::cout << "Ingresa Año: ";
    //std::cin >> date.year;
    employee.date = {
        std::rand() % 30 + 1,
        std::rand() % 12 + 1,
        std::rand() % 32 + 1990
    };

    //std::cout << "\nIngresa los sueldos" << std::endl;
    //for (int i = 0; i < 3; i++) {
    //    std::cout << "Ingresa salario " << i << ": ";
    //    std::cin >> employee.salary[i];
    //}

    for (int i = 0; i < 3; i++) {
        employee.salary[i] = (std::rand() % 100) * 100 + (std::rand() % 100) + (std::rand() % 100) * 0.01;
    }

    return employee;
}

void printEmployeeData(Employee employee) {
    std::cout << "ID:         " << employee.id << std::endl;
    std::cout << "Nombre:     " << employee.name << std::endl;
    std::cout << "Registro:   " << employee.date.day << "/" << employee.date.month << "/" << employee.date.year << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << "Salario " << i + 1 << ":  $" << employee.salary[i] << std::endl;
    }
}

int main()
{
    Employee employees[2];
    // std::cout << "===== Primer Empleado =====" << std::endl;
    // e1 = getEmployeeInput();
    // std::cout << "\n===== Segundo Empleado =====" << std::endl;
    // e2 = getEmployeeInput(); 

    std::srand(time(0));

    for (int i = 0; i < 2; i++) {
        std::cout << "======= Empleado #" << i << " =======" << std::endl;
        employees[i] = getEmployeeInput();
        std::cout << std::endl;
    }

    std::cout << "====== Empleados ======" << std::endl;
    for (int i = 0; i < 2; i++) {
        printEmployeeData(employees[i]);
        if (i < 1) std::cout << std::endl;
    }
    std::cout << "=======================" << std::endl;

    //std::cout << "===== Empleados =====" << std::endl;
    //printEmployeeData(e1);
    //std::cout << std::endl;
    //printEmployeeData(e2);
    //std::cout << "=====================" << std::endl;
    system("pause");
    return 0;
}


