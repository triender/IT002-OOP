#include <iostream>
#include <string>

using namespace std;

int main()
{
    string username = "Username";
    string password = "pass";
    string input_username;
    string input_password;
    int count = 3;

    for (int i = 0; i < count; i++)
    {
        cout << "Nhap username: ";
        cin >> input_username;
        cout << "Nhap password: ";
        cin >> input_password;

        if (input_username == username && input_password == password)
        {
            cout << "Chao " << username << "!\n";
            return 0;
        }
        else
            cout << "Sai ten dang nhap hoac mat khau. Vui long nhap lai.\n";
    }
    cout << "Ban da nhap sai qua 3 lan. Vui long thu lai sau.\n";

    return 0;
}
