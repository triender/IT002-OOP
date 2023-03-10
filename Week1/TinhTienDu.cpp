#include <iostream>

using namespace std;

void TinhTien(int &soTien, int MenhGia)
{
    int soToTien;
    soToTien = soTien / MenhGia;
    soTien %= MenhGia;
    cout << "So to tien " << MenhGia << ": " << soToTien << endl;
}

int main()
{
    int soTien;
    cout << "Nhap so tien: ";
    cin >> soTien;

    TinhTien(soTien, 500000);
    TinhTien(soTien, 200000);
    TinhTien(soTien, 100000);
    TinhTien(soTien, 50000);
    TinhTien(soTien, 20000);
    TinhTien(soTien, 10000);
    TinhTien(soTien, 5000);
    TinhTien(soTien, 2000);
    TinhTien(soTien, 1000);

    return 0;
}
