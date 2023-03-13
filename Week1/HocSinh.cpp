// 5. Viết chương trình nhập họ tên, điểm toán, điểm văn của một học sinh. Tính điểm trung bình và xuất kết quả.
#include <iostream>
#include <string>
using namespace std;

struct HocSinh
{
    string HoTen;
    int DiemToan, DiemVan;
};

void NhapHocSinh(HocSinh &A)
{
    cout << "Nhap ten hoc sinh: ";
    getline(cin, A.HoTen);
    cout << "Nhap diem toan: ";
    cin >> A.DiemToan;
    cout << "Nhap diem van: ";
    cin >> A.DiemVan;
}

float DTB(HocSinh const A)
{
    float DTB = (A.DiemToan + A.DiemVan) / float(2);
    return DTB;
}

int main()
{
    HocSinh A;
    NhapHocSinh(A);
    cout << "DTB: " << DTB(A);
    return 0;
}
