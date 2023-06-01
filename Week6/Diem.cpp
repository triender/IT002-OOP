#include "Diem.h"

DIEM2C::DIEM2C(double xValue, double yValue) : x(xValue), y(yValue) {}

DIEM2C::DIEM2C(const DIEM2C &other) : x(other.x), y(other.x) {}

void DIEM2C::setX(double newX) { x = newX; }
void DIEM2C::setY(double newY) { y = newY; }
double DIEM2C::getX() const { return x; }
double DIEM2C::getY() const { return y; }

// void DIEM2C::nhap() { cin >> x >> y; }

// void DIEM2C::xuat() const { cout << "(" << ((x == -0) ? 0 : x) << ", " << ((y == -0) ? 0 : y) << ")"; }

istream &operator>>(istream &is, DIEM2C &X)
{
    cout << "Nhap toa do X va Y: ";
    is >> X.x >> X.y;
    return is;
}
ostream &operator<<(ostream &os, const DIEM2C &X)
{
    os << "(" << ((x == -0) ? 0 : x) << ", " << ((y == -0) ? 0 : y) << ")";
    return os;
}

DIEM2C &DIEM2C::operator=(const DIEM2C &X)
{
    if (this != &X)
    {
        this->x = X.x;
        this->y = X.y;
    }
    return *this;
}

void DIEM2C::dichX(double dx) { x += dx; }

void DIEM2C::dichY(double dy) { y += dy; }

void DIEM2C::dichXY(double dx, double dy)
{
    x += dx;
    y += dy;
}

void DIEM2C::quay(double goc, const double &tamX, const double &tamY)
{
    double rad = goc * M_PI / 180.0;
    x = cos(rad) * (x - tamX) - sin(rad) * (y - tamY) + tamX;
    y = sin(rad) * (x - tamX) + cos(rad) * (y - tamY) + tamY;
}

double DIEM2C::khoangCach(const DIEM2C &p /*= DIEM2C(0, 0)*/) const
{
    return sqrt(pow(x - p.getX(), 2) + pow(y - p.getY(), 2));
}

int DIEM2C::kiemTraTrung(const DIEM2C &p2)
{
    if (x == p2.getX() && y == p2.getY())
        return 3;
    if (x == p2.getX())
        return 1;
    if (y == p2.getY())
        return 2;
    return 0;
}

DIEM2C DIEM2C::layDoiXung() const { return DIEM2C(-x, -y); }

double DIEM2C::tinhChuVi(const DIEM2C &p2, const DIEM2C &p3) const
{
    return khoangCach(p2) + khoangCach(p3) + p2.khoangCach(p3);
}

double DIEM2C::tinhDienTich(const DIEM2C &p2, const DIEM2C &p3) const
{
    double a = khoangCach(p2);
    double b = khoangCach(p3);
    double c = p2.khoangCach(p3);
    double p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

bool kiemTraTamGiac(const DIEM2C &p1, const DIEM2C &p2, const DIEM2C &p3)
{
    double a = p1.khoangCach(p2);
    double b = p1.khoangCach(p3);
    double c = p2.khoangCach(p3);
    return (a + b > c) && (a + c > b) && (b + c > a);
}

int DIEMMAU::getR() const { return r; }
int DIEMMAU::getG() const { return g; }
int DIEMMAU::getB() const { return b; }
void DIEMMAU::setR(int newR) { r = newR; }
void DIEMMAU::setG(int newG) { g = newG; }
void DIEMMAU::setB(int newB) { b = newB; }
void DIEMMAU::setRGB(int newR, int newG, int newB)
{
    r = newR;
    g = newG;
    b = newB;
}

istream &operator>>(istream &is, DIEMMAU &X)
{
    is >> X.x >> X.y >> X.r >> X.g >> X.b;
    return is;
}

ostream &operator<<(ostream &os, const DIEMMAU &X)
{
    os << X.x << " " << X.y << " " << X.r << " " << X.g << " " << X.b;
    return os;
}

bool DIEMMAU::kiemTraTrung(const DIEMMAU &p2) const
{
    return (getX() == p2.getX() && getY() == p2.getY() && r == p2.r && g == p2.g && b == p2.b);
}