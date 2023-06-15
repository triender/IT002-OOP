#include "STHAMKHAO.h"

STHAMKHAO::STHAMKHAO() : tienThue(0) {}

void STHAMKHAO::nhap() {
    SACH::nhap();
    cout << "Tien thue: ";
    cin >> tienThue;
}

void STHAMKHAO::xuat() {
    SACH::xuat();
    cout << "Tien thue: " << tienThue << "\n";
}

int STHAMKHAO::tinhTien() {
    return soLuong * donGia + tienThue;
}
