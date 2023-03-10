#include <iostream>
using namespace std;

int main()
{
   float length, width;
   cout << "Nhap chieu dai: ";
   cin >> length;
   cout << "Nhap chieu rong: ";
   cin >> width;

   float perimeter = 2 * (length + width);
   float area = length * width;

   cout << "Chu vi hinh chu nhat la: " << perimeter << endl;
   cout << "Dien tich hinh chu nhat la: " << area << endl;

   return 0;
}
