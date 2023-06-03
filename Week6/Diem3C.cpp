#include "Diem3C.h"

DIEM3C::DIEM3C(double xValue, double yValue, double zValue) : DIEM2C(xValue, yValue), z(zValue) {}

DIEM3C::DIEM3C(const DIEM3C &other) : DIEM2C(other), z(other.z) {}

double DIEM3C::getZ() const
{
    return this->z;
}

void DIEM3C::setZ(double zValue)
{
    this->z = zValue;
}

istream &operator>>(istream &is, DIEM3C &X)
{
    is >> X.x >> X.y >> X.z;
    return is;
}

ostream &operator<<(ostream &os, const DIEM3C &X)
{
    os << "(" << (X.x == -0 ? 0 : X.x) << ", " << (X.y == -0 ? 0 : X.y) << ", " << (X.z == -0 ? 0 : X.z) << ")";
    return os;
}

DIEM3C &DIEM3C::operator=(const DIEM3C &X)
{
    if (this != &X)
    {
        DIEM2C::operator=(X);
        z = X.z;
    }
    return *this;
}

void DIEM3C::dichXYZ(double dx, double dy, double dz)
{
    x += dx;
    y += dy;
    z += dz;
}

double DIEM3C::khoangCach(const DIEM3C &p) const
{
    double dx = x - p.x;
    double dy = y - p.y;
    double dz = z - p.z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

int DIEM3C::kiemTraTrung(const DIEM3C &p2)
{
    return (x == p2.x && y == p2.y && z == p2.z);
}

DIEM3C DIEM3C::layDoiXung() const
{
    return DIEM3C(-x, -y, -z);
}

double DIEM3C::tinhChuVi(const DIEM3C &p2, const DIEM3C &p3) const
{
    double a = khoangCach(p2);
    double b = khoangCach(p3);
    double c = p2.khoangCach(p3);
    return a + b + c;
}

double DIEM3C::tinhDienTich(const DIEM3C &p2, const DIEM3C &p3) const
{
    double a = khoangCach(p2);
    double b = khoangCach(p3);
    double c = p2.khoangCach(p3);
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
