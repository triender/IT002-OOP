#include <iostream>

using namespace std;

const int DayInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct Date
{
    int day, month, year;
};

bool isLeapYear(int Nam)
{
    if (Nam % 4 != 0)
        return 0;
    else if (Nam % 100 != 0)
        return 1;
    else if (Nam % 400 != 0)
        return 0;
    else
        return 1;
}

void inputDate(Date &d){
    cin >> d.month >> d.year;
}

int DaysInMonth(Date date)
{
    int days = DayInMonth[date.month];
    if (date.month == 2 && isLeapYear(date.year))
        days++;
    return days;
}

int main()
{
    Date date;
    cout << "Nhap thang va nam (mm/yyyy): ";
    inputDate(date);
    int days = DaysInMonth(date);

    cout << "Thang " << date.month << " nam " << date.year << " co " << days << " ngay." << endl;

    return 0;
}
