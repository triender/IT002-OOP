#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float R, C, S;

    cout << "Nhap ban kinh hinh tron: ";
    cin >> R;

    if (R <= 0)
    {
        cout << "Ban kinh khong hop le!" << endl;
        return 0;
    }

    C = 2 * M_PI * R;
    S = M_PI * pow(R, 2);

    cout << "Chu vi hinh tron la: " << C << endl;
    cout << "Dien tich hinh tron la: " << S << endl;

    return 0;
}
