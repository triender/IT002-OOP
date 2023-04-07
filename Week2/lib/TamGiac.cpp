#include "TamGiac.h"

TamGiac::TamGiac() {}

TamGiac::TamGiac(Diem a, Diem b, Diem c) : A(a), B(b), C(c) {}

void TamGiac::setA(Diem a) { A = a; }

void TamGiac::setB(Diem b) { B = b; }

void TamGiac::setC(Diem c) { C = c; }

Diem TamGiac::getA() const { return A; }

Diem TamGiac::getB() const { return B; }

Diem TamGiac::getC() const { return C; }

void TamGiac::input()
{
    std::cout << "Nhap diem A:\n";
    std::cin >> A;
    std::cout << "Nhap diem B:\n";
    std::cin >> B;
    std::cout << "Nhap diem C:\n";
    std::cin >> C;
    if (!kiemTraTamGiac(A, B, C))
    {
        input();
    }
}

void TamGiac::output() const
{
    std::cout << "Tam giac co dinh tai:\n";
    std::cout << "A: " << A << "\n";
    std::cout << "B: " << B << "\n";
    std::cout << "C: " << C << "\n";
}

std::istream &operator>>(std::istream &is, TamGiac &tamgiac)
{
    std::cout << "Nhap diem A:\n";
    is >> tamgiac.A;
    std::cout << "Nhap diem B:\n";
    is >> tamgiac.B;
    std::cout << "Nhap diem C:\n";
    is >> tamgiac.C;

    if (!kiemTraTamGiac(tamgiac.A, tamgiac.B, tamgiac.C))
    {
        tamgiac.input();
    }
    return is;
}

std::ostream &operator<<(std::ostream &os, const TamGiac &tamgiac)
{
    os << "Tam giac co dinh tai:\n";
    os << "A: " << tamgiac.A << "\n";
    os << "B: " << tamgiac.B << "\n";
    os << "C: " << tamgiac.C << "\n";
    return os;
}

void TamGiac::translateX(double dx)
{
    A.dichX(dx);
    B.dichX(dx);
    C.dichX(dx);
}

void TamGiac::translateY(double dy)
{
    A.dichY(dy);
    B.dichY(dy);
    C.dichY(dy);
}

void TamGiac::translateXY(double dx, double dy)
{
    A.dichXY(dx, dy);
    B.dichXY(dx, dy);
    C.dichXY(dx, dy);
}

Diem TamGiac::getCenter() const
{
    // Calculate the centroid of the triangle
    double centerX = (A.getX() + B.getX() + C.getX()) / 3.0;
    double centerY = (A.getY() + B.getY() + C.getY()) / 3.0;

    return Diem(centerX, centerY);
}

void TamGiac::rotate(double angle)
{
    Diem center = getCenter();

    A.quay(angle, center.getX(), center.getY());
    B.quay(angle, center.getX(), center.getY());
    C.quay(angle, center.getX(), center.getY());
}

void TamGiac::scaleUp(double k)
{
    Diem center = getCenter();

    A.setX(center.getX() + k * (A.getX() - center.getX()));
    A.setY(center.getY() + k * (A.getY() - center.getY()));
    B.setX(center.getX() + k * (B.getX() - center.getX()));
    B.setY(center.getY() + k * (B.getY() - center.getY()));
    C.setX(center.getX() + k * (C.getX() - center.getX()));
    C.setY(center.getY() + k * (C.getY() - center.getY()));
}

void TamGiac::scaleDown(double k)
{
    Diem center = getCenter();

    A.setX(center.getX() + (A.getX() - center.getX()) / k);
    A.setY(center.getY() + (A.getY() - center.getY()) / k);
    B.setX(center.getX() + (B.getX() - center.getX()) / k);
    B.setY(center.getY() + (B.getY() - center.getY()) / k);
    C.setX(center.getX() + (C.getX() - center.getX()) / k);
    C.setY(center.getY() + (C.getY() - center.getY()) / k);
}

double TamGiac::getPerimeter() const
{
    double AB = A.khoangCach(B);
    double BC = B.khoangCach(C);
    double CA = C.khoangCach(A);

    return AB + BC + CA;
}

double TamGiac::getArea() const
{
    double AB = A.khoangCach(B);
    double BC = B.khoangCach(C);
    double AC = C.khoangCach(A);
    double p = (AB + BC + AC) / 2.0;
    return sqrt(p * (p - AB) * (p - BC) * (p - AC));
}

std::string TamGiac::phanLoai() const
{
    double AB = A.khoangCach(B);
    double AC = A.khoangCach(C);
    double BC = B.khoangCach(C);
    const double epsilon = 1e-9;
    
    if (AB <= 0 || AC <= 0 || BC <= 0)
        return "Tam giac khong hop le";

    if (fabs(AB - AC) < epsilon && fabs(AC - BC) < epsilon && fabs(AB - BC) < epsilon)
        return "Tam giac deu";

    if (fabs(AB - AC) < epsilon || fabs(AB - BC) < epsilon || fabs(AC - BC) < epsilon)
    {
        if (fabs(AB * AB + AC * AC - BC * BC) < epsilon || fabs(AB * AB + BC * BC - AC * AC) < epsilon || fabs(AC * AC + BC * BC - AB * AB) < epsilon)
        {
            return "Tam giac vuong can";
        }
        return "Tam giac can";
    }

    if (fabs(AB * AB + AC * AC - BC * BC) < epsilon || fabs(AB * AB + BC * BC - AC * AC) < epsilon || fabs(AC * AC + BC * BC - AB * AB) < epsilon)
        return "Tam giac vuong";

    return "Tam giac thuong";
}
