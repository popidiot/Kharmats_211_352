#include <iostream> 
#include <bitset> 
using std::cout;
using std::cin;
using std::endl;
using namespace std;
int main()
{
    setlocale(LC_ALL, "russian");
    cout << "1." << endl;
    cout << "Nikita Kharmats Alekseevich, 221-352 " << endl;

    cout << "2." << endl;

    int num1 = int(0b01111111111111111111111111111111);
    int num2 = int(0b10000000000000000000000000000000);
    cout << "min int =" << num2 << "," << "max int =" << num1 << "," << "size of int = " << sizeof(int) << "\t" << endl;

    unsigned int num3 = unsigned(0b1000000000000000000000000000000000000000000000000000000000000000);
    unsigned int num4 = unsigned(0b0111111111111111111111111111111111111111111111111111111111111111);
    cout << "min unsigned int =" << num3 << "," << "max unsigned int =" << num4 << "," << "size of unsigned int =" << sizeof(unsigned int) << endl;

    short num5 = short(0b1000000000000000);
    short num6 = short(0b0111111111111111);
    cout << "min short =" << num5 << "," << "max short =" << num6 << "," << "size of short = " << sizeof(short) << "\t" << endl;

    long num7 = long(0b10000000000000000000000000000000);
    long num8 = long(0b01111111111111111111111111111111);
    cout << "min long =" << num7 << "," << "max long =" << num8 << "," << "size of long = " << sizeof(long) << "\t" << endl;

    long long num9 = long long(0b1000000000000000000000000000000000000000000000000000000000000000);
    long long num10 = long long(0b0111111111111111111111111111111111111111111111111111111111111111);
    cout << "min long long =" << num9 << "," << "max long long =" << num10 << "," << "size of long long = " << sizeof(long long) << "\t" << endl;

    double num11 = double(0b1000000000000000000000000000000000000000000000000000000000000000);
    double num12 = double(0b0111111111111111111111111111111111111111111111111111111111111111);
    cout << "min double =" << num11 << "," << "max double =" << num12 << "," << "size of double = " << sizeof(double) << "\t" << endl;

    char num13 = char(0b10000000);
    char num14 = char(0b01111111);
    cout << "min char =" << num13 << "," << "max char =" << num14 << "," << "size of char = " << sizeof(char) << "\t" << endl;

    bool num15 = bool(0b0);
    bool num16 = bool(0b01111111);
    cout << "min bool =" << num15 << "," << "max bool =" << num16 << "," << "size of bool = " << sizeof(bool) << "\t" << endl;

    cout << "3." << endl;
    int u;
    cout << "введите число "; cin >> u;
    cout << "в бинарном виде " << bitset<16>(u) << endl;
    cout << "в шестнадцатиричном виде " << hex << u << endl;
    cout << "bool " << bool(u) << endl;
    cout << "double " << double(u) << endl;
    cout << "char " << char(u) << endl;

    cout << "4." << endl;
    int a, b;
    cout << "введите коафициенты a * x=b: ";
    cin >> a >> b;
    cout << a << "*x=" << b << endl;
    cout << "x=" << double(b) / a << endl;

    cout << "Ответ:" << double(b) / a << endl;
    cout << "5." << endl;
    double k, k1, k2;
    cout << "Введите координаты отрезка на прямой:";
    cin >> k1 >> k2;
    k = (k2 + k1) / 2;
    cout << "Середина отрезка находится в точке с координатой " << k;
}
