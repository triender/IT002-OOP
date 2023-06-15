#ifndef STHAMKHAO_H
#define STHAMKHAO_H

#include "SACH.h"

class STHAMKHAO : public SACH {
protected:
    int tienThue;

public:
    STHAMKHAO();

    void nhap();
    void xuat();
    int tinhTien();
};

#endif
