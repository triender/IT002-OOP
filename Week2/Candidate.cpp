#include <iostream>
#include <string>
using namespace std;

class Candidate {
private:
    string ma;
    string ten;
    string ngaySinh;
    float diemToan;
    float diemVan;
    float diemAnh;

public:
    void NhapThongTin() {
        cout << "Nhap ma: ";
        getline(cin, ma);
        cout << "Nhap ten: ";
        getline(cin, ten);
        cout << "Nhap ngay sinh (dd/mm/yyyy): ";
        getline(cin, ngaySinh);
        cout << "Nhap diem Toan: ";
        cin >> diemToan;
        cout << "Nhap diem Van: ";
        cin >> diemVan;
        cout << "Nhap diem Anh: ";
        cin >> diemAnh;
        cin.ignore();
    }

    float TinhTongDiem() const {
        return diemToan + diemVan + diemAnh;
    }

    void XuatThongTin() const {
        cout << "Thong tin thi sinh:" << endl;
        cout << "Ma: " << ma << endl;
        cout << "Ten: " << ten << endl;
        cout << "Ngay sinh: " << ngaySinh << endl;
        cout << "Diem Toan: " << diemToan << endl;
        cout << "Diem Van: " << diemVan << endl;
        cout << "Diem Anh: " << diemAnh << endl;
        cout << "Tong diem: " << TinhTongDiem() << endl;
    }

    bool operator>(const int n) const {
        return TinhTongDiem() > n;
    }
};

class TestCandidate {
private:
    Candidate* dsThiSinh;
    int n;

public:
    void NhapDanhSachThiSinh() {
        cout << "Nhap so luong thi sinh: ";
        cin >> n;
        cin.ignore();
        dsThiSinh = new Candidate[n];
        for (int i = 0; i < n; i++) {
            cout << "Nhap thong tin thi sinh thu " << i + 1 << endl;
            dsThiSinh[i].NhapThongTin();
        }
    }

    void InDanhSachThiSinhTongDiemLonHon15() const {
        cout << "Danh sach thi sinh co tong diem lon hon 15:" << endl;
        for (int i = 0; i < n; i++) {
            if (dsThiSinh[i].TinhTongDiem() > 15) {
                dsThiSinh[i].XuatThongTin();
            }
        }
    }

    ~TestCandidate() {
        delete[] dsThiSinh;
    }
};

int main() {
    TestCandidate test;
    test.NhapDanhSachThiSinh();
    test.InDanhSachThiSinhTongDiemLonHon15();
    return 0;
}
