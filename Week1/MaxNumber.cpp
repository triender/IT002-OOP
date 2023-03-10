#include <iostream>
using namespace std;

int maxNumber(const int a, const int b, const int c){
    return (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
}

int main()
{
    int a, b, c;
    cout << "Nhap vao ba so nguyen: ";
    cin >> a >> b >> c;
    cout << "So lon nhat trong ba so " << a << ", " << b << ", " << c << " la: " << maxNumber(a, b, c) << endl;
    return 0;
}
