#include "Diem.h"

Diem::Diem(double xValue, double yValue) : x(xValue), y(yValue) {}

void Diem::setX(double newX) { x = newX; }
void Diem::setY(double newY) { y = newY; }
double Diem::getX() const { return x; }
double Diem::getY() const { return y; }

void Diem::nhap() { cin >> x >> y; }

void Diem::xuat() const { cout << "(" << ((x == -0) ? 0 : x) << ", " << ((y == -0) ? 0 : y) << ")"; }

istream& operator>>(istream& is, Diem& X) {
    cout << "Nhap toa do X va Y: ";
    is >> X.x >> X.y;
    return is;
}
ostream& operator<<(ostream& os, const Diem& X) {
    os << "(" << X.x << ", " << X.y << ")";
    return os;
}

void Diem::dichX(double dx) { x += dx; }

void Diem::dichY(double dy) { y += dy; }

void Diem::dichXY(double dx, double dy)
{
    x += dx;
    y += dy;
}

void Diem::quay(double goc, const double &tamX, const double &tamY)
{
    double rad = goc * M_PI / 180.0;
    x = cos(rad) * (x - tamX) - sin(rad) * (y - tamY) + tamX;
    y = sin(rad) * (x - tamX) + cos(rad) * (y - tamY) + tamY;
}

double Diem::khoangCach(const Diem &p /*= Diem(0, 0)*/) const
{
    return sqrt(pow(x - p.getX(), 2) + pow(y - p.getY(), 2));
}

int Diem::kiemTraTrung(const Diem &p2)
{
    if (x == p2.getX() && y == p2.getY())
        return 3;
    if (x == p2.getX())
        return 1;
    if (y == p2.getY())
        return 2;
    return 0;
}

Diem Diem::layDoiXung() const { return Diem(-x, -y); }

double Diem::tinhChuVi(const Diem &p2, const Diem &p3) const
{
    return khoangCach(p2) + khoangCach(p3) + p2.khoangCach(p3);
}

double Diem::tinhDienTich(const Diem &p2, const Diem &p3) const
{
    double a = khoangCach(p2);
    double b = khoangCach(p3);
    double c = p2.khoangCach(p3);
    double p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

bool kiemTraTamGiac(const Diem &p1, const Diem &p2, const Diem &p3)
{
    double a = p1.khoangCach(p2);
    double b = p1.khoangCach(p3);
    double c = p2.khoangCach(p3);
    return (a + b > c) && (a + c > b) && (b + c > a);
}
