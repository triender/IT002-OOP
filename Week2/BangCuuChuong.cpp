#include <iostream>
#include <iomanip>
using namespace std;

class BangCuuChuong
{
private:
    int m, n;

public:
    BangCuuChuong(int m = -1, int n = -1)
    {
        this->m = m;
        this->n = n;
    }

    void InBangCuuChuong()
    {
        if (m == -1 && n == -1)
        {
            // in ra hàng đầu tiên của bảng
            cout << "    ";
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
        else if (n == -1)
        {
            cout << "Bang cuu chuong " << m << ":" << endl;
            for (int i = 1; i <= 10; ++i)
                cout << m << " x " << i << " = " << m * i << endl;
        }
        else
        {
            for (int i = m; i <= n; ++i)
            {
                cout << "Bang cuu chuong " << i << ":" << endl;
                for (int j = 1; j <= 10; ++j)
                    cout << i << " x " << j << " = " << i * j << endl;
                cout << endl;
            }
        }
    }
};

int main()
{
    int m, n, choice;
    do
    {
        cout << "MENU:\n";
        cout << "1. In bang cuu chuong tong hop\n";
        cout << "2. In bang cuu chuong tu m den n\n";
        cout << "3. In bang cuu chuong cua mot so m\n";
        cout << "4. Thoat chuong trinh\n";
        cout << "Nhap lua chon cua ban (1-4): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            BangCuuChuong bcc;
            bcc.InBangCuuChuong();
            break;
        }
        case 2:
        {
            cin >> m;
            BangCuuChuong bcc(m);
            bcc.InBangCuuChuong();
            break;
        }
        case 3:
        {
            cin >> m >> n;
            BangCuuChuong bcc(m, n);
            bcc.InBangCuuChuong();
            break;
        }
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
