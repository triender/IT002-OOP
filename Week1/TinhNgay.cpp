#include <iostream>

using namespace std;

const int kDaysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct Date
{
    int day, month, year;
};

bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

void inputDate(Date &d)
{
    cin >> d.month >> d.year;
}

void outputDate(const Date d){
    cout << d.day << "/" << d.month << "/" << d.year;
}

bool isValidDate(const Date d)
{
    if (d.month < 1 || d.month > 12 || d.year < 0)
        return false;
    return true;
}

int DaysInMonth(Date date)
{
    int days = kDaysInMonth[date.month];
    if (date.month == 2 && isLeapYear(date.year))
        days++;
    return days;
}

int main()
{
    Date date;
    do
    {
        cout << "Nhap thang va nam (mm/yyyy): ";
        inputDate(date);
    } while (!isValidDate(date));
    
    int days = DaysInMonth(date);

    cout << "Thang " << date.month << " nam " << date.year << " co " << days << " ngay." << endl;

    return 0;
}
