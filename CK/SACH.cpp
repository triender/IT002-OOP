#include "SACH.h"

void SACH::nhap()
{
    cout << "Nhap thong tin sach:\n";
    cout << "ID: ";
    cin >> id;
    cout << "Ten sach: ";
    cin.ignore();
    getline(cin, ten);
    cout << "Nha xuat ban: ";
    getline(cin, NXB);
    cout << "So luong: ";
    cin >> soLuong;
    cout << "Don gia: ";
    cin >> donGia;
}

void SACH::xuat()
{
    cout << "Thong tin sach:\n";
    cout << "ID: " << id << "\n";
    cout << "Ten sach: " << ten << "\n";
    cout << "Nha xuat ban: " << NXB << "\n";
    cout << "So luong: " << soLuong << "\n";
    cout << "Don gia: " << donGia << "\n";
}

string SACH::getId() const
{
    return id;
}

string SACH::getTen() const
{
    return ten;
}

string SACH::getNXB() const
{
    return NXB;
}

int SACH::getSoLuong() const
{
    return soLuong;
}

int SACH::getDonGia() const
{
    return donGia;
}

void SACH::setId(const string &newId)
{
    id = newId;
}

void SACH::setTen(const string &newTen)
{
    ten = newTen;
}

void SACH::setNXB(const string &newNXB)
{
    NXB = newNXB;
}

void SACH::setSoLuong(int newSoLuong)
{
    soLuong = newSoLuong;
}

void SACH::setDonGia(int newDonGia)
{
    donGia = newDonGia;
}
