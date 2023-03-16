// 4. Viết chương trình nhập vào một ngày. Tìm ngày kế tiếp và xuất kết quả.
#include <iostream>

using namespace std;

const int kDaysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct Date
{
    int day, month, year;
};

bool isLeapYear(const int year)
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

void inputDate(Date &d)
{
    cin >> d.day >> d.month >> d.year;
}

void outputDate(const Date d){
    cout << d.day << "/" << d.month << "/" << d.year;
}

bool isValidDate(const Date d)
{
    if (d.month < 1 || d.month > 12)
    {
        return false;
    }

    int maxDay = kDaysInMonth[d.month];
    if (d.month == 2 && isLeapYear(d.year))
    {
        maxDay++;
    }

    return d.day >= 1 && d.day <= maxDay;
}

Date nextDate(const Date d)
{
    int newDay = d.day, newMonth = d.month, newYear = d.year;
    if (++newDay > kDaysInMonth[d.month])
    {
        newDay = 1;
        if (++newMonth > 12)
        {
            newMonth = 1;
            ++newYear;
        }
    }
    return Date{newDay, newMonth, newYear};
}

int main(){
    Date d;
    do
    {
        cout << "Nhap ngay, thang ,nam: ";
        inputDate(d);
    } while (!isValidDate(d));
    
    cout << "Ngay tiep theo la: ";
    outputDate((nextDate(d)));
}
