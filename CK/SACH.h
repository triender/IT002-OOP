#ifndef SACH_H
#define SACH_H

#include <iostream>
#include <string>

using namespace std;

class SACH {
protected:
    string id, ten, NXB;
    int soLuong, donGia;

public:
    SACH() = default;
    ~SACH() = default;

    virtual void nhap();
    virtual void xuat();
    virtual int tinhTien() = 0;

    string getId() const;
    string getTen() const;
    string getNXB() const;
    int getSoLuong() const;
    int getDonGia() const;

    void setId(const string&);
    void setTen(const string&);
    void setNXB(const string&);
    void setSoLuong(int);
    void setDonGia(int);
};

#endif
