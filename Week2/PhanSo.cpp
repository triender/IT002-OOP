#include <iostream>
using namespace std;

int GCD(int a, int b)
{
    if (a == 0 || b == 0)
        return a + b;
    while (a != b)
    {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}

class PhanSo
{
private:
    int Tu, Mau;

public:
    PhanSo() {}
    PhanSo(int Tu, int Mau)
    {
        this->Tu = Tu;
        this->Mau = Mau;
        this->rutGon();
    }

    int getTu() const { return Tu; }
    int getMau() const { return Mau; }
    void setTu(int Tu)
    {
        this->Tu = Tu;
        this->rutGon();
    }
    void setMau(int Mau)
    {
        this->Mau = Mau;
        this->rutGon();
    }

    void nhap()
    {
        cout << "Nhap Tu so: ";
        cin >> Tu;
        cout << "Nhap Mau so: ";
        cin >> Mau;
        this->rutGon();
    }

    void xuat()
    {
        if (Mau == 0)
            return;
        if (Mau < 0)
        {
            Tu *= -1;
            Mau *= -1;
        }
        if (Mau == 1)
            cout << Tu;
        else
            cout << Tu << "/" << Mau;
    }

    PhanSo cong(const PhanSo ps)
    {
        PhanSo ketQua;
        ketQua.Tu = this->Tu * ps.Mau + this->Mau * ps.Tu;
        ketQua.Mau = this->Mau * ps.Mau;
        ketQua.rutGon();
        return ketQua;
    }

    PhanSo tru(const PhanSo ps)
    {
        PhanSo ketQua;
        ketQua.Tu = this->Tu * ps.Mau - this->Mau * ps.Tu;
        ketQua.Mau = this->Mau * ps.Mau;
        ketQua.rutGon();
        return ketQua;
    }

    PhanSo nhan(const PhanSo ps)
    {
        PhanSo ketQua;
        ketQua.Tu = this->Tu * ps.Tu;
        ketQua.Mau = this->Mau * ps.Mau;
        ketQua.rutGon();
        return ketQua;
    }

    PhanSo chia(const PhanSo ps)
    {
        PhanSo ketQua;
        ketQua.Tu = this->Tu * ps.Mau;
        ketQua.Mau = this->Mau * ps.Tu;
        ketQua.rutGon();
        return ketQua;
    }

    PhanSo operator+(const PhanSo ps)
    {
        PhanSo ketQua;
        ketQua.Tu = this->Tu * ps.Mau + this->Mau * ps.Tu;
        ketQua.Mau = this->Mau * ps.Mau;
        ketQua.rutGon();
        return ketQua;
    }

    PhanSo operator-(const PhanSo ps)
    {
        PhanSo ketQua;
        ketQua.Tu = this->Tu * ps.Mau - this->Mau * ps.Tu;
        ketQua.Mau = this->Mau * ps.Mau;
        ketQua.rutGon();
        return ketQua;
    }

    PhanSo operator*(const PhanSo ps)
    {
        PhanSo ketQua;
        ketQua.Tu = this->Tu * ps.Tu;
        ketQua.Mau = this->Mau * ps.Mau;
        ketQua.rutGon();
        return ketQua;
    }

    PhanSo operator/(const PhanSo ps)
    {
        PhanSo ketQua;
        ketQua.Tu = this->Tu * ps.Mau;
        ketQua.Mau = this->Mau * ps.Tu;
        ketQua.rutGon();
        return ketQua;
    }

    void rutGon()
    {
        int UCLN = GCD(abs(Tu), abs(Mau));
        Tu /= UCLN;
        Mau /= UCLN;
    }
};

int main()
{
    PhanSo ps1, *ps2 = new PhanSo();

    cout << "Nhap phan so 1" << endl;
    ps1.nhap();
    cout << "Nhap phan so 2" << endl;
    ps2->nhap();

    cout << "Phan so 1 la: ";
    ps1.xuat();
    cout << "\nPhan so 2 la: ";
    ps2->xuat();
    // không dùng định nghĩa lại toán tử
    // PhanSo tong = ps1.cong(*ps2);
    // cout << "\nTong 2 phan so: ";
    // tong.xuat();

    // PhanSo hieu = ps1.tru(*ps2);
    // cout << "\nHieu 2 phan so: ";
    // hieu.xuat();

    // PhanSo tich = ps1.nhan(*ps2);
    // cout << "\nTich 2 phan so: ";
    // tich.xuat();

    // PhanSo thuong = ps1.chia(*ps2);
    // cout << "\nThuong 2 phan so: ";
    // thuong.xuat();

    // dùng định nghĩa lại toán tử
    PhanSo tong = ps1 + *ps2;
    cout << "\nTong 2 phan so: ";
    tong.xuat();

    PhanSo hieu = ps1 - *ps2;
    cout << "\nHieu 2 phan so: ";
    hieu.xuat();

    PhanSo tich = ps1 * *ps2;
    cout << "\nTich 2 phan so: ";
    tich.xuat();

    PhanSo thuong = ps1 / *ps2;
    cout << "\nThuong 2 phan so: ";
    thuong.xuat();

    return 0;
}
