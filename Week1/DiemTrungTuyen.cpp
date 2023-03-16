#include <iostream>

using namespace std;

int main()
{
    float diemChuan, diemMon1, diemMon2, diemMon3;
    char maKhuVuc, maDoiTuong;

    cout << "Nhap diem chuan: ";
    cin >> diemChuan;

    cout << "Nhap diem 3 mon thi: ";
    cin >> diemMon1 >> diemMon2 >> diemMon3;

    cout << "Nhap ma khu vuc (A/B/C): ";
    cin >> maKhuVuc;

    cout << "Nhap ma doi tuong (1/2/3): ";
    cin >> maDoiTuong;

    float diemUuTienKhuVuc = 0.0;
    float diemUuTienDoiTuong = 0.0;

    switch (maKhuVuc)
    {
    case 'A':
        diemUuTienKhuVuc = 1.5;
        break;
    case 'B':
        diemUuTienKhuVuc = 1.0;
        break;
    case 'C':
        diemUuTienKhuVuc = 0.5;
        break;
    default:
        break;
    }

    switch (maDoiTuong)
    {
    case '1':
        diemUuTienDoiTuong = 1.5;
        break;
    case '2':
        diemUuTienDoiTuong = 1.0;
        break;
    case '3':
        diemUuTienDoiTuong = 0.5;
        break;
    default:
        break;
    }

    float tongDiem = diemMon1 + diemMon2 + diemMon3 + diemUuTienKhuVuc + diemUuTienDoiTuong;

    if (tongDiem >= diemChuan && diemMon1 > 0 && diemMon2 > 0 && diemMon3 > 0)
        cout << "Trung tuyen!" << endl;
    else
        cout << "Khong trung tuyen." << endl;

    return 0;
}
