#include <iostream>
using namespace std;

class GiaiPTBac1 {
private:
    float a, b;

public:
    GiaiPTBac1(float a = 0, float b = 0) {
        this->a = a;
        this->b = b;
    }

    void input() {
        cout << "Nhap 2 he so a, b: ";
        cin >> a >> b;
    }

    void solve() {
        if (a == 0) {
            if (b == 0) {
                cout << "Phuong trinh vo so nghiem" << endl;
            } else {
                cout << "Phuong trinh vo nghiem" << endl;
            }
        } else {
            float x = -b / a;
            cout << "Phuong trinh co nghiem x = " << x << endl;
        }
    }

    void output() {
        cout << "Phuong trinh " << a << "x + " << b << " = 0" << endl;
    }
};

int main() {
    int choice = 0;
    while (choice != 4) {
        cout << "Nhap lua chon cua ban:" << endl;
        cout << "1. Giai phuong trinh 0x + 0 = 0" << endl;
        cout << "2. Giai phuong trinh 2x - 3 = 0" << endl;
        cout << "3. Nhap va giai phuong trinh" << endl;
        cout << "4. Thoat chuong trinh" << endl;
        cin >> choice;

        switch (choice) {
            case 1: {
                GiaiPTBac1 pt;
                pt.output();
                pt.solve();
                break;
            }
            case 2: {
                GiaiPTBac1 pt(2, -3);
                pt.output();
                pt.solve();
                break;
            }
            case 3: {
                GiaiPTBac1 pt;
                pt.input();
                pt.output();
                pt.solve();
                break;
            }
            case 4: {
                cout << "Chuong trinh ket thuc." << endl;
                break;
            }
            default: {
                cout << "Lua chon khong hop le, vui long chon lai." << endl;
                break;
            }
        }
    }

    return 0;
}
