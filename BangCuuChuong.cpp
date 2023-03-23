#include <iostream>
#include <iomanip>
using namespace std;

class BangCuuChuong
{
private:
    int m, n;

public:
    BangCuuChuong(int m = 2, int n = 9)
    {
        if (m < 2 || m > 9)
            m = 2;
        if (n < 2 || n > 9)
            n = 9;
        this->m = m;
        this->n = n;
    }

    void input()
    {
        do
        {
            cout << "Nhap m, n (2 <= m <= n <= 9): ";
            cin >> m >> n;
        } while (m < 2 || n > 9 || m > n);
    }

    void printBangCuuChuongM()
    {
        cout << "Bang cuu chuong " << m << ":" << endl;
        for (int i = 1; i <= 10; ++i)
        {
            cout << m << " x " << i << " = " << m * i << endl;
        }
    }

    void printBangCuuChuongMN()
    {
        for (int i = m; i <= n; ++i)
        {
            cout << "Bang cuu chuong " << i << ":" << endl;
            for (int j = 1; j <= 10; ++j)
            {
                cout << i << " x " << j << " = " << i * j << endl;
            }
            cout << endl;
        }
    }

    void printBangCuuChuongTongHop()
    {
        // in ra hàng đầu tiên của bảng
        cout << "   ";
        for (int i = 1; i <= 9; i++)
            cout << setw(3) << i << " ";
        cout << endl;

        // in ra dòng ngăn cách
        cout << "   +-----------------------------------\n";

        // in ra các hàng còn lại của bảng
        for (int i = 1; i <= 9; i++)
        {
            cout << setw(2) << i << " |";
            for (int j = 1; j <= 9; j++)
                cout << setw(3) << i * j << " ";
            cout << endl;
        }
    }
};

int main() {
    int choice;
    BangCuuChuong bcc;

    do {
        cout << "MENU:\n";
        cout << "1. In bang cuu chuong tu 2 den 9\n";
        cout << "2. In bang cuu chuong tu m den n\n";
        cout << "3. In bang cuu chuong cua mot so m\n";
        cout << "4. Thoat chuong trinh\n";
        cout << "Nhap lua chon cua ban (1-4): ";
        cin >> choice;

        switch (choice) {
            case 1:
                bcc.printBangCuuChuongTongHop();
                break;
            case 2:
                bcc.input();
                bcc.printBangCuuChuongMN();
                break;
            case 3:
                bcc.input();
                bcc.printBangCuuChuongM();
                break;
            case 4:
                cout << "Cam on ban da su dung chuong trinh!\n";
                break;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai!\n";
                break;
        }
    } while (choice != 4);

    return 0;
}
