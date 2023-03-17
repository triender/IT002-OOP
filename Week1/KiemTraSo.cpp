#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

bool isPerfectSquare(int n)
{
    int s = sqrt(n);
    return (s * s == n);
}

bool isPerfectNumber(int n)
{
    int sum = 1;
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
            sum += i;
    }
    return (n == sum);
}

bool isPalindrome(int n)
{
    int temp = n, reverse = 0;
    while (temp != 0)
    {
        reverse = reverse * 10 + temp % 10;
        temp /= 10;
    }
    return (n == reverse);
}

int main()
{
    int n;
    cout << "Nhap mot so nguyen: ";
    cin >> n;

    if (isPrime(n))
        cout << n << " la so nguyen to" << endl;

    if (isPerfectSquare(n))
        cout << n << " la so chinh phuong" << endl;

    if (isPerfectNumber(n))
        cout << n << " la so hoan thien" << endl;

    if (isPalindrome(n))
        cout << n << " la so doi xung" << endl;

    if (!isPrime(n) && !isPerfectSquare(n) && !isPerfectNumber(n) && !isPalindrome(n))
        cout << n << " khong thuoc bat ky loai so nao tren";
    
    return 0;
}
