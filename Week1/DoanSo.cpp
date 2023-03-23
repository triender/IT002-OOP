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
    int score = 10;
    cout << secretNumber;
    int guess;
    do
    {
        cout << "Nhap mot so tu 1 den 100: ";
        cin >> guess;

        if (guess == secretNumber)
        {
            cout << "Chuc mung! Ban da doan dung." << endl;
            cout << "So diem cua ban la: " << score << endl;
            break;
        }
        else
        {
            score--;
            if (guess < secretNumber)
                cout << "So ban nhap vao nho hon so can tim. Moi ban doan lai." << endl;
            else
                cout << "So ban nhap vao lon hon so can tim. Moi ban doan lai." << endl;
        }

        if (score == 0)
        {
            cout << "Ban da het diem roi. Tro choi ket thuc." << endl;
            break;
        }

    } while (true);

    return 0;
}
