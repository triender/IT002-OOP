#include <iostream>
#include <cmath>

using namespace std;

void GiaiPhuongTrinhBac1(int b, int c)
{
    int x;
    if (b == 0)
    {
        if (c == 0)
        {
            cout << "Phuong trinh co vo so nghiem" << endl;
        }
        else
        {
            cout << "Phuong trinh vo nghiem" << endl;
        }
    }
    else
    {
        x = -c / b;
        cout << "Phuong trinh co nghiem duy nhat x = " << x << endl;
    }
}

void GiaiPhuongTrinhbac2(int a, int b, int c)
{
    int delta = b * b - 4 * a * c;
    int x1, x2;

    if (delta < 0)
    {
        cout << "Phuong trinh vo nghiem" << endl;
    }
    else if (delta == 0)
    {
        x1 = -b / (2 * a);
        cout << "Phuong trinh co nghiem kep x = " << x1 << endl;
    }
    else
    {
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);
        cout << "Phuong trinh co hai nghiem phan biet:" << endl;
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }
}

int main()
{
    float a, b, c;

    cout << "Nhap he so a: ";
    cin >> a;

    cout << "Nhap he so b: ";
    cin >> b;

    cout << "Nhap he so c: ";
    cin >> c;

    if (a == 0)
        GiaiPhuongTrinhBac1(b, c);
    else 
        GiaiPhuongTrinhbac2(a, b, c);

    return 0;
}
