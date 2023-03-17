#include <iostream>
#include <cmath>

using namespace std;

double circleArea(double r)
{
    return M_PI * r * r;
}

double rectangleArea(double w, double h)
{
    return w * h;
}

double triangleArea(double b, double h)
{
    return 0.5 * b * h;
}

int main()
{
    int choice;
    double radius, width, height, base;

    do
    {
        cout << "Chon hinh can tinh dien tich: " << endl;
        cout << "1. Hinh tron" << endl;
        cout << "2. Hinh chu nhat" << endl;
        cout << "3. Hinh tam giac" << endl;
        cout << "0. Thoat" << endl;
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Nhap ban kinh hinh tron: ";
                cin >> radius;
                cout << "Dien tich hinh tron la: " << circleArea(radius) << endl;
                break;
            case 2:
                cout << "Nhap chieu rong va chieu cao hinh chu nhat: ";
                cin >> width >> height;
                cout << "Dien tich hinh chu nhat la: " << rectangleArea(width, height) << endl;
                break;
            case 3:
                cout << "Nhap do dai day va chieu cao hinh tam giac: ";
                cin >> base >> height;
                cout << "Dien tich hinh tam giac la: " << triangleArea(base, height) << endl;
                break;
            case 0:
                cout << "Thoat khoi chuong trinh!" << endl;
                break;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai!" << endl;
                break;
        }

    } while (choice != 0);

    return 0;
}
