#ifndef SGIAOKHOA_H
#define SGIAOKHOA_H

#include "SACH.h"

class SGIAOKHOA : public SACH {
protected:
    bool tinhTrang;

public:
    SGIAOKHOA();

    void nhap();
    void xuat();
    int tinhTien();
};

#endif
