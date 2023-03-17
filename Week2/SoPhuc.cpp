#include <iostream>
using namespace std;

class SoPhuc
{
private:
    int thuc, ao;

public:
    SoPhuc() {}
    SoPhuc(int thuc = 0, int ao = 0)
    {
        this->thuc = thuc;
        this->ao = ao;
    }

    int getThuc() const { return thuc; }
    int getAo() const { return ao; }
    void setThuc(int thuc) { this->thuc = thuc; }
    void setAo(int ao) { this->ao = ao; }

    void nhap()
    {
        cout << "Nhap phan thuc: ";
        cin >> thuc;
        cout << "Nhap phan ao: ";
        cin >> ao;
    }

    void xuat() const
    {
        if (ao == 0)
        {
            cout << thuc;
            return;
        }
        if (thuc != 0)
            cout << thuc << " " << ((ao > 0) ? '+' : '-') << " ";
        cout << abs(ao) << "i";
    }

    SoPhuc cong(const SoPhuc &sp) const
    {
        return SoPhuc(this->thuc + sp.thuc, this->ao + sp.ao);
    }

    SoPhuc tru(const SoPhuc sp) const
    {
        return SoPhuc(this->thuc - sp.thuc, this->ao - sp.ao);
    }

    SoPhuc nhan(const SoPhuc sp) const
    {
        return SoPhuc(this->thuc * sp.thuc - this->ao * sp.ao, this->thuc * sp.ao + this->ao * sp.thuc);
    }

    SoPhuc chia(const SoPhuc sp) const
    {
        int mau = sp.thuc * sp.thuc + sp.ao * sp.ao;
        return SoPhuc((this->thuc * sp.thuc + this->ao * sp.ao) / mau, (this->ao * sp.thuc - this->thuc * sp.ao) / mau);
    }

    SoPhuc operator+(const SoPhuc sp) const
    {
        return SoPhuc(this->thuc + sp.thuc, this->ao + sp.ao);
    }

    SoPhuc operator-(const SoPhuc &sp) const
    {
        return SoPhuc(this->thuc - sp.thuc, this->ao - sp.ao);
    }

    SoPhuc operator*(const SoPhuc &sp) const
    {
        return SoPhuc(this->thuc * sp.thuc - this->ao * sp.ao, this->thuc * sp.ao + this->ao * sp.thuc);
    }

    SoPhuc operator/(const SoPhuc &sp) const
    {
        int mau = sp.thuc * sp.thuc + sp.ao * sp.ao;
        return SoPhuc((this->thuc * sp.thuc + this->ao * sp.ao) / mau, (this->ao * sp.thuc - this->thuc * sp.ao) / mau);
    }
};

int main()
{
    SoPhuc sp1, *sp2 = new SoPhuc;

    cout << "Nhap so phuc 1: " << endl;
    sp1.nhap();
    cout << "Nhap so phuc 2: " << endl;
    sp2->nhap();

    // không dùng định nghĩa lại toán tử
    // SoPhuc tong = sp1.cong(*sp2);
    // cout << "Tong 2 so phuc: ";
    // tong.xuat();

    // SoPhuc hieu = sp1.tru(*sp2);
    // cout << "\nHieu 2 so phuc: ";
    // hieu.xuat();

    // SoPhuc tich = sp1.nhan(*sp2);
    // cout << "\nTich 2 so phuc: ";
    // tich.xuat();

    // SoPhuc thuong = sp1.chia(*sp2);
    // cout << "\nThuong 2 so phuc: ";
    // thuong.xuat();

    // dùng định nghĩa lại toán tử
    SoPhuc tong = sp1 + *sp2;
    cout << "\nTong 2 so phuc: ";
    tong.xuat();

    SoPhuc hieu = sp1 - *sp2;
    cout << "\nHieu 2 so phuc: ";
    hieu.xuat();

    SoPhuc tich = sp1 * *sp2;
    cout << "\nTich 2 so phuc: ";
    tich.xuat();

    SoPhuc thuong = sp1 / *sp2;
    cout << "\nThuong 2 so phuc: ";
    thuong.xuat();

    return 0;
}
