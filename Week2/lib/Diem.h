#include <iostream>
#include <cmath>
using namespace std;

class Diem
{
private:
    double x, y;

public:
    Diem(double xValue = 0, double yValue = 0);
    void setX(double newX);
    void setY(double newY);
    double getX() const;
    double getY() const;

    void nhap();
    void xuat() const;
    friend istream& operator>>(istream& is, Diem& X);
    friend ostream& operator<<(ostream& os, const Diem& X);
    void dichX(double dx);
    void dichY(double dy);
    void dichXY(double dx, double dy);
    void quay(double goc, const double &tamX = 0, const double &tamY = 0);
    double khoangCach(const Diem &p = Diem(0, 0)) const;
    int kiemTraTrung(const Diem &p2);
    Diem layDoiXung() const;
    double tinhChuVi(const Diem &p2, const Diem &p3) const;
    double tinhDienTich(const Diem &p2, const Diem &p3) const;
};

bool kiemTraTamGiac(const Diem &p1, const Diem &p2, const Diem &p3);
