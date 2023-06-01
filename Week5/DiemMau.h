#ifndef DIEMMAU_H
#define DIEMMAU_H

#include "Diem.h"

class DIEMMAU : public DIEM2C
{
private:
    int r, g, b;

public:
    DIEMMAU(int r = 0, int g = 0, int b = 0);
    ~DIEMMAU() = default;

    int getR() const;
    int getG() const;
    int getB() const;
    void setR(int);
    void setG(int);
    void setB(int);
    void setRGB(int, int, int);

    friend istream &operator>>(istream &is, DIEMMAU &X);
    friend ostream &operator<<(ostream &os, const DIEMMAU &X);

    bool kiemTraTrung(const DIEMMAU& p2) const;
};

#endif
