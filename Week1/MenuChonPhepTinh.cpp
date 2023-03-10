#include <iostream>
using namespace std;

float cong(float a, float b) {
    return a + b;
}

float tru(float a, float b) {
    return a - b;
}

float nhan(float a, float b) {
    return a * b;
}

float chia(float a, float b) {
    if (b == 0) {
        cout << "Khong the thuc hien phep chia cho so 0." << endl;
        return 0;
    }
    return a / b;
}

float nhapSo() {
    float num;
    cout << "Vui long nhap so: ";
    cin >> num;
    return num;
}

int main() {
    float a, b, kq;
    int chon;

    while (true) {
        cout << "Chuong trinh thuc hien phep toan co ban (+ - x :) cua hai so a, b" << endl;
        a = nhapSo();
        b = nhapSo();

        cout << "Vui long chon phep toan muon thuc hien:" << endl;
        cout << "1. Cong hai so a va b (+)" << endl;
        cout << "2. Tru so b tu so a (-)" << endl;
        cout << "3. Nhan hai so a va b (*)" << endl;
        cout << "4. Chia so a cho so b (/)" << endl;
        cout << "5. Thoat chuong trinh" << endl;
        
        cout << "Nhap lua chon cua ban (1/2/3/4/5): ";
        cin >> chon;

        switch (chon) {
            case 1:
                kq = cong(a, b);
                cout << "Ket qua cua phep tinh la: " << kq << endl;
                break;

            case 2:
                kq = tru(a, b);
                cout << "Ket qua cua phep tinh la: " << kq << endl;
                break;

            case 3:
                kq = nhan(a, b);
                cout << "Ket qua cua phep tinh la: " << kq << endl;
                break;

            case 4:
                kq = chia(a, b);
                cout << "Ket qua cua phep tinh la: " << kq << endl;
                break;

            case 5:
                cout << "Thoat chuong trinh" << endl;
                return 0;

            default:
                cout << "Lua chon khong hop le. Vui long nhap lai." << endl;
                break;
        }
    }
    return 0;
}
