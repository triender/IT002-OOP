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
    void rutGon()
    {
        int UCLN = GCD(abs(Tu), abs(Mau));
        Tu /= UCLN;
        Mau /= UCLN;
        if (Mau < 0)
        {
            Tu *= -1;
            Mau *= -1;
        }
    }
    PhanSo(int Tu = 0, int Mau = 1)
    {
        this->Tu = Tu;
        this->Mau = Mau;
        rutGon();
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
        rutGon();
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

    PhanSo cong(const PhanSo ps) const
    {
        return PhanSo(this->Tu * ps.Mau + this->Mau * ps.Tu, this->Mau * ps.Mau);
    }

    PhanSo tru(const PhanSo ps) const
    {
        return PhanSo(this->Tu * ps.Mau - this->Mau * ps.Tu, this->Mau * ps.Mau);
    }

    PhanSo nhan(const PhanSo ps) const
    {
        return PhanSo(this->Tu * ps.Tu, this->Mau * ps.Mau);
    }

    PhanSo chia(const PhanSo ps) const
    {
        return PhanSo(this->Tu * ps.Mau, this->Mau * ps.Tu);
    }

    int lonHon(const PhanSo ps) const
    {
        return ((this->Tu * ps.getMau()) > (this->Mau * ps.getTu())) ? 1 : 0;
    }

    int beHon(const PhanSo ps) const
    {
        return (this->Tu * ps.getMau()) < (this->Mau * ps.getTu());
    }

    PhanSo operator+(const PhanSo ps) const
    {
        return PhanSo(this->Tu * ps.Mau + this->Mau * ps.Tu, this->Mau * ps.Mau);
    }

    PhanSo operator-(const PhanSo ps) const
    {
        return PhanSo(this->Tu * ps.Mau - this->Mau * ps.Tu, this->Mau * ps.Mau);
    }

    PhanSo operator*(const PhanSo ps) const
    {
        return PhanSo(this->Tu * ps.Tu, this->Mau * ps.Mau);
    }

    PhanSo operator/(const PhanSo ps) const
    {
        return PhanSo(this->Tu * ps.Mau, this->Mau * ps.Tu);
    }

    int operator>(const PhanSo ps) const
    {
        return (this->Tu * ps.getMau()) > (this->Mau * ps.getTu());
    }

    int operator<(const PhanSo ps) const
    {
        return (this->Tu * ps.getMau()) < (this->Mau * ps.getTu());
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

    cout << "\nPhan so lon hon la: ";
    if (ps1 > *ps2)
        ps1.xuat();
    else 
        ps2->xuat();
    
    return 0;
}
