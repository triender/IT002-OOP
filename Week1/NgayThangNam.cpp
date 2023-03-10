// 4. Viết chương trình nhập vào một ngày. Tìm ngày kế tiếp và xuất kết quả.
#include <iostream>
#include <algorithm>
using namespace std;

class NgayThangNam
{
private:
    int Ngay, Thang, Nam;
    const int NgayTrongThang[12] = {31, 28, 31, 30, 31, 30,
                                    31, 31, 30, 31, 30, 31};

public:
    NgayThangNam(int Ngay, int Thang, int Nam)
    {
        this->Ngay = Ngay;
        this->Thang = Thang;
        this->Nam = Nam;
    }
    bool KiemTraNamHopLe() const
    {
        if (Nam > 0)
            return 1;
        return 0;
    }
    bool KiemTraThangHopLe() const
    {
        if (Thang > 0 && Thang < 13)
            return 1;
        return 0;
    }
    bool KiemTraNamNhuan() const
    {
        if (Nam % 4 != 0)
            return 0;
        else if (Nam % 100 != 0)
            return 1;
        else if (Nam % 400 != 0)
            return 0;
        else
            return 1;
    }
    bool KiemTraNgayHopLe() const
    {
        if (Ngay > NgayTrongThang[Thang - 1] && Thang != 2)
            return 0;
        else
        {
            int NgayTrongThang_ = NgayTrongThang[1];
            if (KiemTraNamNhuan())
                NgayTrongThang_++;
            if (Ngay > NgayTrongThang_)
                return 0;
        }
        return 1;
    }
    bool KiemTraNgayThangNamHopLe() const
    {
        if (KiemTraNamHopLe() && KiemTraThangHopLe() && KiemTraNgayHopLe())
            return 1;
        return 0;
    }
    NgayThangNam NgayTiepTheo() const
    {
        int NgayMoi = Ngay, ThangMoi = Thang, NamMoi = Nam;
        if (++NgayMoi > NgayTrongThang[Thang - 1])
        {
            NgayMoi = 1;
            if (++ThangMoi > 12)
            {
                ThangMoi = 1;
                ++NamMoi;
            }
        }
        return NgayThangNam(NgayMoi, ThangMoi, NamMoi);
    }
    int DemNamNhuan() const
    {
        int SoNam = Nam;
        SoNam--;
        return SoNam / 4 - SoNam / 100 + SoNam / 400;
    }
    
    long long DemNgay() const
    {
        long int n1 = Nam * 365 + Ngay;
        for (int i = 0; i < Thang - 1; i++)
            n1 += NgayTrongThang[i];
        n1 += DemNamNhuan();
        return n1;
    }

    void Display() const
    {
        cout << Ngay << "/" << Thang << "/" << Nam;
    }
};

int main()
{
    // A.Display();
    // if (A.KiemTraNgayThangNamHopLe())
    // {
    //     cout << " la ngay hop le";
    //     // cout << "\nNgay tiep theo la: ";
    //     // (A.NgayTiepTheo()).Display();
    // }
    // else
    //     cout << " la ngay khong hop le";
    // cout << endl;
    // B.Display();
    // if (B.KiemTraNgayThangNamHopLe())
    // {
    //     cout << " la ngay hop le";
    //     // cout << "\nNgay tiep theo la: ";
    //     // (B.NgayTiepTheo()).Display();
    // }
    // else
    //     cout << " la ngay khong hop le";
    // cout << "\nKhoang cach giua 2 ngay la " << abs(A.DemNgay() - B.DemNgay());
    return 0;
}
