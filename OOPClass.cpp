// Class-19-04-21.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <regex>
#include <sstream>

struct Time {
    int hours, minutes;
};

/*
*   getTime Function -> (Time time)
*       - Get a time in string
*       - Get the hours: no more than 23 hrs or set 0
*       - Get the minutes: if it's more or equal than 60, add 1 hour and rest 60 minutes
*       - Return a Time with the hours and minutes
*/
Time getTime(std::string time) {
    int hours, minutes;
    std::smatch m;
    std::regex_search(time, m, std::regex("^[0-9]{1,2}"));
    hours = std::stoi(m[0]) % 24;
    std::regex_search(time, m, std::regex("[0-9]{1,2}$"));
    if (std::stoi(m[0]) <= 60) {
        minutes = std::stoi(m[0]);
    }
    else {
        hours++;
        minutes = std::stoi(m[0]) - 60;
    }
    return Time{ hours, minutes };
}


/*
*   sumTime Function -> (Time time)
*       - Get 2 Times
*       - Sum the hours: get the module of 24
*       - Sum the minutes: if it's more or equal to 60, add 1 hour and rest 60 minutes
*       - Return a Time with the hours and minutes
*/
Time sumTime(Time a, Time b) {
    int hours, minutes;
    hours = (a.hours + b.hours) % 24;
    minutes = a.minutes + b.minutes;

    if (minutes >= 60) {
        hours++;
        minutes -= 60;
    }

    return Time{ hours, minutes };
}

/*
*   timeStr Function -> (std::string string)
*       - Get a Time
*       - Format hours: if it's minus than 10, add the 1st zero
*       - Format minutes: if it's mines than 10, add the 1st zero
*       - Format time
*       - Return a string with the time in hh:mm format
*/
std::string timeStr(Time time) {
    std::stringstream ss;
    std::string hours, minutes;

    if (time.hours < 10) {
        ss << "0" << time.hours;
        hours = ss.str();
        ss.str("");
    }
    else {
        hours = std::to_string(time.hours);
    }

    if (time.minutes < 10) {
        ss << "0" << time.minutes;
        minutes = ss.str();
        ss.str("");
    }
    else {
        minutes = std::to_string(time.minutes);
    }

    ss << hours << ":" << minutes;

    return ss.str();
}


int main()
{
    Time timeA, timeB, timeC;
    std::string time;

    std::cout << "Ingresa la primera hora (hh:mm): ";
    std::cin >> time;
    timeA = getTime(time); // Converts string to Time struct

    std::cout << "Ingresa la segunda hora (hh:mm): ";
    std::cin >> time;
    timeB = getTime(time);

    timeC = sumTime(timeA, timeB); // Sums 2 Times struct

    std::cout << "\nLa hora es " << timeStr(timeC) << std::endl; // Converts and Get a string from a Time struct

    std::cout << "\nUn programa de Mario Hdez (~^u^)~" << std::endl;

    //std::cout << "===== Empleados =====" << std::endl;
    //printEmployeeData(e1);
    //std::cout << std::endl;
    //printEmployeeData(e2);
    //std::cout << "=====================" << std::endl;
    system("pause");
    return 0;
}


