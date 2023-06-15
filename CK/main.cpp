#include <vector>
#include <algorithm>
#include "SACH.cpp"
#include "STHAMKHAO.cpp"
#include "SGIAOKHOA.cpp"

class THUVIEN
{
private:
    vector<SACH *> dsSach;

public:
    void nhapDS();
    void xuatDS();
    void timNXB(const string &nxb);
    void timMin();
};

void THUVIEN::nhapDS()
{
    int n;
    cout << "Nhap so luong sach: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        char loai;
        cout << "\nNhap loai sach (G: Sach Giao Khoa, T: Sach Tham Khao): ";
        cin >> loai;

        SACH *sach;
        if (loai == 'G')
        {
            sach = new SGIAOKHOA();
        }
        else if (loai == 'T')
        {
            sach = new STHAMKHAO();
        }
        else
        {
            cout << "Loai sach khong hop le!";
            continue;
        }

        sach->nhap();
        dsSach.push_back(sach);
    }
}

void THUVIEN::xuatDS()
{
    for (const auto &sach : dsSach)
    {
        sach->xuat();
        cout << "Thanh tien: " << sach->tinhTien() << "\n\n";
    }
}

void THUVIEN::timNXB(const string &nxb)
{
    bool found = false;
    for (auto &sach : dsSach)
    {
        if (sach->getNXB() == nxb)
        {
            sach->xuat();
            cout << "Thanh tien: " << sach->tinhTien() << "\n\n";
            found = true;
        }
    }

    if (!found)
    {
        cout << "Khong tim thay sach cua nha xuat ban " << nxb << "\n\n";
    }
}

void THUVIEN::timMin()
{
    if (dsSach.empty())
    {
        cout << "Danh sach sach rong!\n";
        return;
    }

    int min;
    for (const auto &sach : dsSach)
    {
        if(min > sach->tinhTien())
            min = sach->tinhTien();
    }
    
    for (const auto &sach : dsSach)
    {
        if(sach->tinhTien() == min)
        {
            sach->xuat();
            cout << "Thanh tien: " << sach->tinhTien() << "\n\n";
        }
    }
}

int main()
{
    THUVIEN thuVien;

    thuVien.nhapDS();

    cout << "\nDanh sach sach:\n";
    thuVien.xuatDS();

    string nxb;
    cout << "Nhap ten nha xuat ban can tim: ";
    cin.ignore();
    getline(cin, nxb);
    thuVien.timNXB(nxb);

    cout << "Sach co thanh tien nho nhat:\n";
    thuVien.timMin();

    return 0;
}
