#include <iostream>

using namespace std;

struct Date {
    int day, month, year;
};

int main()
{

    Date date;
    cout << "Enter your birthday\n" << "Day: ";
    cin >> date.day;
    cout << "Month: ";
    cin >> date.month;
    cout << "Year: ";
    cin >> date.year;

    cout << "Your birthday is: " << date.day << "/" << date.month << "/" << date.year << endl;


    Date date2;
    cout << "\nEnter your graduation date\n" << "Day: ";
    cin >> date2.day;
    cout << "Month: ";
    cin >> date2.month;
    cout << "Year: ";
    cin >> date2.year;

    cout << "Your Graduation date is: " << date2.day << "/" << date2.month << date2.year << endl;

    system("pause");
}

