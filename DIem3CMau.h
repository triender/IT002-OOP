#ifndef DIEM3CMAU_H
#define DIEM3CMAU_H

#include "Diem.h"
#include "DiemMau.h"
#include "Diem3C.h"

class DIEM3CMAU : public DIEM3C, DIEMMAU
{
public:
    DIEM3CMAU(double xValue = 0, double yValue = 0, double zValue = 0);
    DIEM3CMAU(const DIEM3CMAU &other);

    ~DIEM3CMAU() = default;
    friend istream &operator>>(istream &is, DIEM3CMAU &X);
    friend ostream &operator<<(ostream &os, const DIEM3CMAU &X);
    friend DIEM3CMAU &operator=(const DIEM3CMAU &X);
};

#endif