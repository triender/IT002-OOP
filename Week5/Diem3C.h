#ifndef DIEM3C_H
#define DIEM3C_H

#include "Diem.h"

class DIEM3C : public DIEM2C
{
private:
    double z;

public:
    DIEM3C(double xValue = 0, double yValue = 0, double zValue = 0);
    DIEM3C(const DIEM3C &other);

    ~DIEM3C() = default;

    friend istream &operator>>(istream &is, DIEM3C &X);
    friend ostream &operator<<(ostream &os, const DIEM3C &X);
    friend DIEM3C &operator=(const DIEM3C &X);

    double khoangCach(const DIEM3C &p = DIEM3C(0, 0, 0)) const;
    int kiemTraTrung(const DIEM3C &p2);
    DIEM3C layDoiXung() const;
    double tinhChuVi(const DIEM3C &p2, const DIEM3C &p3) const;
    double tinhDienTich(const DIEM3C &p2, const DIEM3C &p3) const;
};

#endif