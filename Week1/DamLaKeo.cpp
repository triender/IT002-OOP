#include <bits/stdc++.h>

using namespace std;

int GetRandom()
{
    return (rand() % 3) + 1;
}

int GetUserChoice()
{
    int choice;
    cout << "Moi ban nhap lua chon tu 1 den 3: ";
    do
    {
        cin >> choice;
    } while (choice < 1 || choice > 3);

    return choice;
}

void ShowChoice(int choice)
{
    if (choice == 1)
        cout << "lua chon cua ban la Dam\n";
    else if (choice == 2)
        cout << "lua chon cua ban la La\n";
    else
        cout << "lua chon cua ban la Keo\n";
}

void ShowComputerChoice(int choice)
{
    if (choice == 1)
        cout << "Lua chon cua may la Dam\n";
    else if (choice == 2)
        cout << "Lua chon cua may la La\n";
    else
        cout << "Lua chon cua may la Keo\n";
}

void DetermineWinner(int userChoice, int computerChoice)
{
    if (userChoice == computerChoice)
        cout << "Ban da hoa\n";
    else if ((userChoice == 1 && computerChoice == 3) || (userChoice == 2 && computerChoice == 1) || (userChoice == 3 && computerChoice == 2))
        cout << "Ban da thang\n";
    else
        cout << "Ban da thua\n";
}

bool PlayAgain()
{
    char response;
    cout << "Choi tiep bam Y, bam bat ky de thoat: ";
    cin >> response;

    return (response == 'Y' || response == 'y');
}

int main()
{
    srand(time(0)); 
    bool playAgain = true;

    while (playAgain)
    {
        int computerChoice = GetRandom();
        int userChoice = GetUserChoice();

        ShowChoice(userChoice);
        ShowComputerChoice(computerChoice);
        DetermineWinner(userChoice, computerChoice);

        playAgain = PlayAgain();
    }

    return 0;
}
