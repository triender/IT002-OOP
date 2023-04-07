#include "Diem.h"
#include <string>

class TamGiac
{
private:
    Diem A, B, C;

public:
    TamGiac();
    TamGiac(Diem a, Diem b, Diem c);

    void setA(Diem a);
    void setB(Diem b);
    void setC(Diem c);
    Diem getA() const;
    Diem getB() const;
    Diem getC() const;

    void input();
    void output() const;

    friend std::ostream &operator<<(std::ostream &os, const TamGiac &tamgiac);
    friend std::istream &operator>>(std::istream &is, TamGiac &tamgiac);

    void translateX(double dx);
    void translateY(double dy);
    void translateXY(double dx, double dy);
    Diem getCenter() const;
    void rotate(double angle);
    void scaleUp(double k);
    void scaleDown(double k);
    double getPerimeter() const;
    double getArea() const;
    string phanLoai() const;
};
