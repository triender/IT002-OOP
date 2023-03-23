#include <iostream>
#include <string>
using namespace std;

void standardizeName(string &name)
{
    int length = name.length();

    // Remove non-letter characters
    for (int i = 0; i < length; i++)
    {
        if (!isalpha(name[i]) && !isspace(name[i]))
        {
            name.erase(i, 1);
            length--;
            i--;
        }
    }

    // Remove consecutive spaces
    for (int i = 0; i < length - 1; i++)
    {
        if (name[i] == ' ' && name[i + 1] == ' ')
        {
            name.erase(i, 1);
            length--;
            i--;
        }
    }

    // Remove leading and trailing spaces
    while (length > 0 && isspace(name[length - 1]))
    {
        name.erase(length - 1, 1);
        length--;
    }
    while (isspace(name[0]))
    {
        name.erase(0, 1);
        length--;
    }

    // Capitalize first letter of each word
    name[0] = toupper(name[0]);
    for (int i = 1; i < length; i++)
    {
        if (isspace(name[i - 1]))
            name[i] = toupper(name[i]);
        else
            name[i] = tolower(name[i]);
    }
}


class HocSinh
{
private:
    string hoTen;
    float diemVan;
    float diemToan;

public:
    HocSinh()
    {
        hoTen = "";
        diemVan = 0;
        diemToan = 0;
    }

    HocSinh(string ten, float van, float toan)
    {
        hoTen = ten;
        diemVan = van;
        diemToan = toan;
        standardizeName(hoTen);
    }

    void nhap()
    {
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);
        cout << "Nhap diem Van: ";
        cin >> diemVan;
        cout << "Nhap diem Toan: ";
        cin >> diemToan;
        standardizeName(hoTen);
    }

    void xuat()
    {
        cout << "Ho ten: " << hoTen << endl;
        cout << "Diem Van: " << diemVan << endl;
        cout << "Diem Toan: " << diemToan << endl;
    }

    float tinhDTB()
    {
        return (diemVan + diemToan) / 2.0;
    }

    string xepLoai()
    {
        float dtb = tinhDTB();
        if (dtb >= 8.0)
            return "Gioi";
        else if (dtb >= 6.5)
            return "Kha";
        else if (dtb >= 5.0)
            return "Trung binh";
        else
            return "Yeu";
    }
};

int main()
{
    HocSinh hs1;
    hs1.nhap();
    cout << "\nThong tin hoc sinh vua nhap:" << endl;
    hs1.xuat();
    cout << "Diem trung binh: " << hs1.tinhDTB() << endl;
    cout << "Xep loai: " << hs1.xepLoai() << endl;

    HocSinh hs2("Nguyen Van A", 8.5, 7.0);
    cout << "\nThong tin hoc sinh 2:" << endl;
    hs2.xuat();
    cout << "Diem trung binh: " << hs2.tinhDTB() << endl;
    cout << "Xep loai: " << hs2.xepLoai() << endl;

    return 0;
}
