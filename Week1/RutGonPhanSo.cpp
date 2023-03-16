// 1. Viết chương trình nhập vào một phân số, rút gọn phân số và xuất kết quả.
// 2. Viết chương trình nhập vào hai phân số, tìm phân số lớn nhất và xuất kết quả.
// 3. Viết chương trình nhập vào hai phân số. Tính tổng, hiệu, tích, thương giữa chúng và xuất kết quả.
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

struct PhanSo
{
    int Tu, Mau;
};

void RutGon(PhanSo &A)
{
    int UCLN = GCD(abs(A.Tu), abs(A.Mau));
    A.Tu /= UCLN;
    A.Mau /= UCLN;
    if (A.Mau < 0)
    {
        A.Tu *= -1;
        A.Mau *= -1;
    }
}

void RutGon(PhanSo *&A)
{
    int UCLN = GCD(abs(A->Tu), abs(A->Mau));
    A->Tu /= UCLN;
    A->Mau /= UCLN;
    if (A->Mau < 0)
    {
        A->Tu *= -1;
        A->Mau *= -1;
    }
}

void Nhap(PhanSo &A)
{
    cout << "Nhap tu: ";
    cin >> A.Tu;
    do
    {
        cout << "Nhap mau (khac 0): ";
        cin >> A.Mau;
    } while (!A.Mau);
    RutGon(A);
}

void Nhap(PhanSo *&A)
{
    cout << "Nhap tu: ";
    A = new PhanSo;
    cin >> A->Tu;
    do
    {
        cout << "Nhap mau (khac 0): ";
        cin >> A->Mau;
    } while (!A->Mau);
    RutGon(A);
}

int Xuat(PhanSo A)
{
    if (A.Mau == 0)
        return 0;
    if (A.Mau == 1)
        cout << A.Tu;
    else
        cout << A.Tu << "/" << A.Mau;
    return 1;
}

int Xuat(PhanSo *A)
{
    if (A->Mau == 0)
        return 0;
    if (A->Mau == 1)
        cout << A->Tu;
    else
        cout << A->Tu << "/" << A->Mau;
    return 1;
}

PhanSo PhanSoLonNhat(PhanSo A, PhanSo B)
{
    int Tu_1 = A.Tu * B.Mau;
    int Tu_2 = B.Tu * A.Mau;
    if (Tu_1 > Tu_2)
        return A;
    return B;
}

PhanSo *PhanSoLonNhat(PhanSo *A, PhanSo *B)
{
    int Tu_1 = A->Tu * B->Mau;
    int Tu_2 = B->Tu * A->Mau;
    if (Tu_1 >= Tu_2)
        return A;
    return B;
}

PhanSo Cong(PhanSo A, PhanSo B)
{
    PhanSo C;
    C.Mau = (A.Mau * B.Mau);
    C.Tu = (A.Tu * B.Mau + B.Tu * A.Mau);
    RutGon(C);
    return C;
}

PhanSo *Cong(PhanSo *A, PhanSo *B)
{
    PhanSo *C = new PhanSo;
    C->Mau = (A->Mau * B->Mau);
    C->Tu = (A->Tu * B->Mau + B->Tu * A->Mau);
    RutGon(C);
    return C;
}

PhanSo Tru(PhanSo A, PhanSo B)
{
    PhanSo C;
    C.Mau = (A.Mau * B.Mau);
    C.Tu = (A.Tu * B.Mau - B.Tu * A.Mau);
    RutGon(C);
    return C;
}

PhanSo *Tru(PhanSo *A, PhanSo *B)
{
    PhanSo *C = new PhanSo;
    C->Mau = (A->Mau * B->Mau);
    C->Tu = (A->Tu * B->Mau - B->Tu * A->Mau);
    RutGon(C);
    return C;
}

PhanSo Nhan(PhanSo A, PhanSo B)
{
    PhanSo C;
    C.Mau = (A.Mau * B.Mau);
    C.Tu = (A.Tu * B.Tu);
    RutGon(C);
    return C;
}

PhanSo *Nhan(PhanSo *A, PhanSo *B)
{
    PhanSo *C = new PhanSo;
    C->Mau = (A->Mau * B->Mau);
    C->Tu = (A->Tu * B->Tu);
    RutGon(C);
    return C;
}

PhanSo Chia(PhanSo A, PhanSo B)
{
    PhanSo C;
    C.Mau = (A.Mau * B.Tu);
    if (C.Mau == 0)
    {
        cout << "Khong chia duoc.";
        return {0, 0};
    }
    C.Tu = (A.Tu * B.Mau);
    RutGon(C);
    return C;
}

PhanSo *Chia(PhanSo *A, PhanSo *B)
{
    PhanSo *C = new PhanSo;
    C->Mau = (A->Mau * B->Tu);
    if (C->Mau == 0)
    {
        cout << "Khong chia duoc->";
        return nullptr;
    }
    C->Tu = (A->Tu * B->Mau);
    RutGon(C);
    return C;
}

int main()
{
    PhanSo *A, *B;
    Nhap(A);
    Xuat(A);
    cout << endl;

    Nhap(B);
    Xuat(B);

    cout << "\nPhan so thu nhat la: ";
    Xuat(A);
    cout << "\nPhan so thu hai la: ";
    Xuat(B);

    cout << "\nPhan so lon nhat la: ";
    Xuat(PhanSoLonNhat(A, B));
    cout << "\nKet qua cong phan so la: ";
    Xuat(Cong(A, B));
    cout << "\nKet qua tru phan so la: ";
    Xuat(Tru(A, B));
    cout << "\nKet qua nhan phan so la: ";
    Xuat(Nhan(A, B));
    cout << "\nKet qua chia phan so la: ";
    Xuat(Chia(A, B));
    return 0;
}
