#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0 || b == 0)
        return a + b;
    while (a != b)
    {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int main()
{
    int a, b;
    cout << "Nhap vao 2 so a, b: ";
    cin >> a >> b;

    cout << "USCLN cua " << a << " va " << b << " la: " << gcd(a, b) << endl;
    cout << "BSCNN cua " << a << " va " << b << " la: " << lcm(a, b) << endl;

    return 0;
}