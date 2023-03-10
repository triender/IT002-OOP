#include <iostream>
using namespace std;

int main()
{
    int decimalNumber, binaryNumber = 0;

    cout << "Nhap vao so thap phan: ";
    cin >> decimalNumber;

    int i = 1;
    do
    {
        binaryNumber = binaryNumber + (decimalNumber % 2) * i;
        i *= 10;
        decimalNumber /= 2;
    } while (decimalNumber);

    cout << "So nhi phan chuyen doi la: " << binaryNumber;

    return 0;
}
