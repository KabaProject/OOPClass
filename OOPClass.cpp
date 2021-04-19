/*
   Tarea-17-04-2021.cpp :
   Declare a struct that represent a complex number (a+bi)
   The program will display the sum of two complex numbers whose will been give it by the user
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <regex>
#include <sstream>

struct complexNumber {
    float a = 0, b = 0; // Complex number (a + bi) where a is the real part and b the imaginary part
};

/*
    getComplex Function -> (complexNumber struct)
    - Get a string with the complex number
    - If exists, get the real value (a). Otherwise, set a = 0
    - If exists, get the imaginary value (b) without "i". Othewise, set b = 0
    - Return a complexNumber with the a and b values
*/
complexNumber getComplex(std::string complex) {
    float a = 0, b = 0;
    std::smatch m;
    std::regex_search(complex, m, std::regex("(\\-)?[0-9\.]+(?=(\\+|\\-)?)(?!i)"));
    if (m.size() != 0) { a = std::stof(m[0]); }
    else { a = 0; }
    std::regex_search(complex, m, std::regex("(\\-)?[0-9\.]+(?=i)"));
    if (m.size() != 0) { b = std::stof(m[0]); }
    else { b = 0; }

    return complexNumber{ a, b };
}

/*
    sumComplex Function -> (complexNumber)
    - Get two complexNumber structs
    - Sum the reals and imaginaries values
    - Return a complexNumber with the new values
*/
complexNumber sumComplex(complexNumber num1, complexNumber num2) {
    float a = 0, b = 0;
    a = num1.a + num2.a;
    b = num1.b + num2.b;

    return complexNumber{ a, b };
}

/*
    printResult Function -> (void)
    - Format the output text
    - Print the values with 2 decimals
    - If the one of values is 0, don't will be added
    - Print a formated text
*/
void printResult(complexNumber total) {
    std::stringstream ss;
    std::string prefix = "The result is: ";
    if (total.a == 0 && total.b == 0) {
        ss << prefix << 0;
    }
    else if (total.a == 0) {
        ss << prefix;
        ss << std::fixed << std::setprecision(2) << total.b;
        ss << "i";
    }
    else if (total.b == 0) {
        ss << prefix;
        ss << std::fixed << std::setprecision(2) << total.a;
    }
    else {
        ss << prefix;
        ss << std::fixed << std::setprecision(2) << total.a;
        if (total.b >= 0) ss << "+";
        ss << std::fixed << std::setprecision(2) << total.b;
        ss << "i";
    }

    std::cout << ss.str() << std::endl;
}

int main()
{
    complexNumber num1, num2, total;
    std::string complex;

    std::cout << "Enter the first number in the \"a+bi\" shape: ";
    std::cin >> complex;
    num1 = getComplex(complex); // Convert the string to a complexNumber struct

    std::cout << "Enter the second number in the \"a+bi\" shape: ";
    std::cin >> complex;
    num2 = getComplex(complex);

    total = sumComplex(num1, num2); // Get the sum of two complexNumber structs

    printResult(total);

    std::cout << "\nCreado por Mario Hdez (\\^o^/)\n";

    system("pause");

    return 0;
}

