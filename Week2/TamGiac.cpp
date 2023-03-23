#include <iostream>
#include <cmath>

using namespace std;

class TamGiac
{
private:
    double a, b, c;

public:
    TamGiac(double x = 0, double y = 0, double z = 0)
    {
        a = x;
        b = y;
        c = z;
    }

    void nhap()
    {
        cout << "Nhap do dai 3 canh tam giac: ";
        cin >> a >> b >> c;
    }

    void xuat()
    {
        cout << "Do dai 3 canh tam giac la: " << a << ", " << b << ", " << c << endl;
    }

    bool kiemTraHopLe()
    {
        return (a + b > c && a + c > b && b + c > a);
    }

    string phanLoaiTamGiac()
    {
        if (!kiemTraHopLe())
            return "Khong phai tam giac";
        if (a == b && b == c)
            return "Tam giac deu";
        if (a == b || a == c || b == c)
            return "Tam giac can";
        if (pow(a, 2) == pow(b, 2) + pow(c, 2) || pow(b, 2) == pow(a, 2) + pow(c, 2) || pow(c, 2) == pow(a, 2) + pow(b, 2))
            return "Tam giac vuong";
        return "Tam giac thuong";
    }

    double tinhChuVi()
    {
        return a + b + c;
    }

    double tinhDienTich()
    {
        double p = tinhChuVi() / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
};

int main()
{
    TamGiac A(1, 3, 12);
    cout << A.phanLoaiTamGiac();
    return 0;
}