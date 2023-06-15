#include "SGIAOKHOA.h"
#include <iostream>

SGIAOKHOA::SGIAOKHOA() : tinhTrang(true) {}

void SGIAOKHOA::nhap() {
    SACH::nhap();
    cout << "Tinh trang (0: cu, 1: moi): ";
    cin >> tinhTrang;
}

void SGIAOKHOA::xuat() {
    SACH::xuat();
    cout << "Tinh trang: " << (tinhTrang ? "Moi" : "Cu") << "\n";
}

int SGIAOKHOA::tinhTien() {    
    if(tinhTrang)
        return soLuong * donGia;
    else
        return soLuong * donGia * 0.5;
}
