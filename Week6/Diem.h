#ifndef DIEM_H
#define DIEM_H

#include <bits/stdc++.h>
using namespace std;

class DIEM2C
{
protected:
    double x, y;

public:
    DIEM2C(double xValue = 0, double yValue = 0);
    DIEM2C(const DIEM2C &other);

    ~DIEM2C() = default;

    void setX(double newX);
    void setY(double newY);
    double getX() const;
    double getY() const;

    // void nhap();
    // void xuat() const;

    friend istream &operator>>(istream &is, DIEM2C &X);
    friend ostream &operator<<(ostream &os, const DIEM2C &X);
    virtual DIEM2C &operator=(const DIEM2C &X);

    void dichX(double dx);
    void dichY(double dy);
    void dichXY(double dx, double dy);
    // void quay(double goc, const double &tamX = 0, const double &tamY = 0);

    virtual double khoangCach(const DIEM2C &p = DIEM2C(0, 0)) const;
    virtual int kiemTraTrung(const DIEM2C &p2);
    DIEM2C layDoiXung() const;
    virtual double tinhChuVi(const DIEM2C &p2, const DIEM2C &p3) const;
    virtual double tinhDienTich(const DIEM2C &p2, const DIEM2C &p3) const;
};

bool kiemTraTamGiac(const DIEM2C &p1, const DIEM2C &p2, const DIEM2C &p3);

#endif // DIEM_H
