#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int GetRandom()
{
    return (rand() % 3) + 1;
}

void GetUserInput(int Input)
{
    cout << "Moi ban nhap";
    cin >> Input;
}

int main()
{
    bool Run = true;
    int runcheck;

    while (Run)
    {
        cout << "1 la Dam\n";
        cout << "2 la La\n";
        cout << "3 la keo\n";
        cout << "Moi ban nhap lua chon tu 1 den 3: ";
        int ComputerChoice = GetRandom();
        // CheckInput
        int YourChoice;
        do
        {
            cin >> YourChoice;
        } while (YourChoice < 1 && YourChoice >);

        // Show User choice
        if (YourChoice == 1)
            cout << "lua chon cua ban la Dam\n";
        else if (YourChoice == 2)
            cout << "lua chon cua ban la La\n";
        else
            cout << "lua chon cua ban la Keo\n";

        // Show computer choice
        if (ComputerChoice == 1)
            cout << "Lua chon cua may la Dam\n";
        else if (ComputerChoice == 2)
            cout << "Lua chon cua may la La\n";
        else
            cout << "Lua chon cua may la Keo\n";

        // Determine Who is the Winner
        if (YourChoice == ComputerChoice)
            cout << "Ban da hoa\n";
        else if ((YourChoice == 1 && ComputerChoice == 3) || (YourChoice == 2 && ComputerChoice == 1) || (YourChoice == 3 && ComputerChoice == 2))
            cout << "Ban da thang\n";
        else
            cout << "Ban da thua\n";

        cout << "Choi tiep bam 1: ";
        cin >> runcheck;
        (runcheck == 1) ? Run = true : Run = false;
    }
    return 0;
}
