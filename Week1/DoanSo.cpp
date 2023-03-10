#include <bits/stdc++.h>
using namespace std;

int random()
{
    return rand() % 100;
}

int main()
{
    srand(time(0));
    int secretNumber = random();
    cout << secretNumber;
    int guess;
    do
    {
        cout << "Nhap mot so tu 1 den 10000: ";
        cin >> guess;

        if (guess == secretNumber)
        {
            cout << "Chuc mung! Ban da doan dung." << endl;
            break;
        }
        else if (guess < secretNumber)
            cout << "So ban nhap vao nho hon so can tim. Moi ban doan lai." << endl;
        else
            cout << "So ban nhap vao lon hon so can tim. Moi ban doan lai." << endl;

    } while (true);
    return 0;
}