#include <iostream>

using namespace std;

int main()
{
    float diem_trung_binh;
    cout << "Nhap diem trung binh cua hoc sinh: ";
    cin >> diem_trung_binh;

    if (diem_trung_binh < 0 || diem_trung_binh > 10)
    {
        cout << "Diem trung binh khong hop le!" << endl;
        return 0;
    }

    if (diem_trung_binh >= 9)
        cout << "Hoc sinh xep loai: Xuat sac" << endl;
    else if (diem_trung_binh >= 8)
        cout << "Hoc sinh xep loai: Gioi" << endl;
    else if (diem_trung_binh >= 7)
        cout << "Hoc sinh xep loai: Kha" << endl;
    else if (diem_trung_binh >= 5)
        cout
            << "Hoc sinh xep loai: Trung binh" << endl;
    else
        cout << "Hoc sinh xep loai: Yeu" << endl;

    return 0;
}
