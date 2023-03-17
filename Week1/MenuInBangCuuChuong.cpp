#include <iostream>
#include <iomanip>
using namespace std;

void printMultiplicationTable(int n)
{
    for (int i = 1; i <= 10; i++)
        cout << setw(2) << n << " x " << setw(2) << i << " = " << setw(3) << n * i << endl;
}

void printMultiplicationTableRange(int m, int n)
{
    for (int i = m; i <= n; i++)
    {
        printMultiplicationTable(i);
        cout << endl;
    }
}

void printMultiplicationTableSummary()
{
    // in ra hàng đầu tiên của bảng
    cout << "   ";
    for (int i = 1; i <= 10; i++)
        cout << setw(3) << i << " ";
    cout << endl;

    // in ra dòng ngăn cách
    cout << "   +---------------------------------------\n";

    // in ra các hàng còn lại của bảng
    for (int i = 1; i <= 10; i++)
    {
        cout << setw(2) << i << " |";
        for (int j = 1; j <= 10; j++)
            cout << setw(3) << i * j << " ";
        cout << endl;
    }
}


int main()
{
    int choice;
    int n, m;

    do
    {
        cout << "Menu:\n";
        cout << "1. In ra bang cuu chuong thu n.\n";
        cout << "2. In ra bang cuu chuong tu m den n.\n";
        cout << "3. In ra bang cuu chuong tong hop.\n";
        cout << "4. Thoat chuong trinh.\n";
        cout << "Moi ban chon: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Nhap so n: ";
            cin >> n;
            printMultiplicationTable(n);
            break;
        case 2:
            cout << "Nhap so m: ";
            cin >> m;
            cout << "Nhap so n: ";
            cin >> n;
            printMultiplicationTableRange(m, n);
            break;
        case 3:
            printMultiplicationTableSummary();
            break;
        case 4:
            cout << "Tam biet!\n";
            break;
        default:
            cout << "Khong co lua chon nay. Moi ban chon lai.\n";
            break;
        }
    } while (choice != 4);

    return 0;
}
