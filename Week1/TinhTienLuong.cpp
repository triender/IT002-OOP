#include <iostream>
using namespace std;

struct Time
{
    int hour;
    int minute;
    int second;
    Time()
    {
        hour = 0;
        minute = 0;
        second = 0;
    }
    int toSeconds()
    {
        return hour * 3600 + minute * 60 + second;
    }
    int toMinutes()
    {
        return hour * 60 + minute;
    }
    void getTime()
    {
        cout << "Nhap gio: ";
        cin >> hour;
        cout << "Nhap phut: ";
        cin >> minute;
        cout << "Nhap giay: ";
        cin >> second;
    }
    void display()
    {
        cout << hour << ":" << minute << ":" << second;
    }
    bool checkValidTime()
    {
        if (hour >= 0 && hour < 24 && minute >= 0 && minute < 60 && second >= 0 && second < 60)
            return true;
        return false;
    }
};

int calculateTimeDifference(Time start, Time end)
{
    int startInSeconds = start.hour * 3600 + start.minute * 60 + start.second;
    int endInSeconds = end.hour * 3600 + end.minute * 60 + end.second;
    return endInSeconds - startInSeconds;
}

double calculateSalary(Time inTime, Time outTime)
{
    double salary = 0.0;
    int inHour = inTime.hour, outHour = outTime.hour;

    if (inHour < 6) inHour = 6;
    if (outHour > 18) outHour = 18;

    int inMinutes = inTime.toMinutes();
    int outMinutes = outTime.toMinutes();

    int workHours = (outMinutes - inMinutes) / 60;
    if (workHours > 8) workHours = 8;

    if (inHour < 12) salary = workHours * 6000;
    else salary = workHours * 7500;

    return salary;
}

int main()
{
    Time start, end;
    do
    {
        cout << "Nhap gio vao ca:\n";
        start.getTime();
    } while (!start.checkValidTime());

    do
    {
        cout << "Nhap gio ra ca:\n";
        end.getTime();
    } while (!end.checkValidTime());

    float salary = calculateSalary(start, end);
    cout << "Tien luong ngay cua cong nhan: " << salary << " VND\n";
    return 0;
}
