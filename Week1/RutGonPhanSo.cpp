// 1. Viết chương trình nhập vào một phân số, rút gọn phân số và xuất kết quả.
// 2. Viết chương trình nhập vào hai phân số, tìm phân số lớn nhất và xuất kết quả.
// 3. Viết chương trình nhập vào hai phân số. Tính tổng, hiệu, tích, thương giữa chúng và xuất kết quả.
#include <iostream>
using namespace std;

// Giải thuật
// Greatest common divisor
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
// vét cạn
// int UCLN(int A, int B)
// {
//         if (A == 0 || B == 0)
//         return A + B;
//     for (int i = min(A, B); i > 0; --i)
//     {
//         if (A % i == 0 && B % i == 0)
//         return i;
//     }
// }
class PhanSo
{
private:
    int Mau, Tu;

public:
    int GetMau()
    {
        return Mau;
    }
    int GetTu()
    {
        return Tu;
    }
    void SetMau(int Data)
    {
        this->Mau = Data;
    }
    void SetTu(int Data)
    {
        this->Tu = Data;
    }
    void RutGon()
    {
        int UCLN = GCD(abs(Tu), abs(Mau));
        Tu /= UCLN;
        Mau /= UCLN;
    }
    int Display()
    {
        if (Mau == 0)
            return 0;
        if (Mau < 0)
        {
            Tu *= -1;
            Mau *= -1;
        }
        if (Mau == 1)
            cout << Tu;
        else
            cout << Tu << "/" << Mau;
        return 1;
    }
};
PhanSo PhanSoLonNhat(PhanSo A, PhanSo B)
{
    int MauChung = A.GetMau() * B.GetMau();
    int Tu_1 = A.GetTu() * B.GetMau();
    int Tu_2 = B.GetTu() * A.GetMau();
    if (Tu_1 > Tu_2)
        return A;
    else
        return B;
}
PhanSo Cong(PhanSo A, PhanSo B)
{
    PhanSo C;
    C.SetMau(A.GetMau() * B.GetMau());
    C.SetTu(A.GetTu() * B.GetMau() + B.GetTu() * A.GetMau());
    C.RutGon();
    return C;
}
PhanSo Tru(PhanSo A, PhanSo B)
{
    PhanSo C;
    C.SetMau(A.GetMau() * B.GetMau());
    C.SetTu(A.GetTu() * B.GetMau() - B.GetTu() * A.GetMau());
    C.RutGon();
    return C;
}
PhanSo Nhan(PhanSo A, PhanSo B)
{
    PhanSo C;
    C.SetMau(A.GetMau() * B.GetMau());
    C.SetTu(A.GetTu() * B.GetTu());
    C.RutGon();
    return C;
}
PhanSo Chia(PhanSo A, PhanSo B)
{
    PhanSo C;
    C.SetMau(A.GetMau() * B.GetTu());
    C.SetTu(A.GetTu() * B.GetMau());
    C.RutGon();
    return C;
}
int main()
{
    PhanSo A, B;

    A.SetTu(-22);
    A.SetMau(-4);
    A.RutGon();
    A.Display();
    // B.SetTu(1);
    // B.SetMau(2);

    // A.RutGon();
    // B.RutGon();
    // cout << "Phan so dau tien la: ";
    // A.Display();
    // cout << "\nPhan so thu hai la: ";
    // B.Display();
    // cout << "\nPhan so lon nhat la: ";
    // PhanSoLonNhat(A, B).Display();
    // cout << "\nKet qua cong phan so la: ";
    // Cong(A, B).Display();
    // cout << "\nKet qua tru phan so la: ";
    // Tru(A, B).Display();
    // cout << "\nKet qua nhan phan so la: ";
    // Nhan(A, B).Display();
    // cout << "\nKet qua chia phan so la: ";
    // Chia(A, B).Display();
    return 0;
}
