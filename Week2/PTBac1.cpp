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
    GiaiPTBac1 pt1;  // Khởi tạo phương trình 0x + 0 = 0
    pt1.output();  // Xuất phương trình
    pt1.solve();  // Giải phương trình

    GiaiPTBac1 pt2(2, -3);  // Khởi tạo phương trình 2x - 3 = 0
    pt2.output();
    pt2.solve();

    GiaiPTBac1 pt3;
    pt3.input();  // Nhập 2 hệ số a, b
    pt3.output();
    pt3.solve();

    return 0;
}
