#include <iostream>
using namespace std;

bool isVowel(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;
    else if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        return true;
    return false;
}

bool isValidChar(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return true;
    return false;
}

int main()
{
    char c;
    do
    {
        cout << "Nhap vao mot ki tu: ";
    cin >> c;
    } while (!isValidChar(c));
    
    if (isVowel(c))
        cout << "Day la nguyen am.\n";
    else
        cout << "Day la phu am.\n";
    return 0;
}
