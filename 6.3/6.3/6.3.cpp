#include <iostream>

using namespace std;

unsigned calculate(int b) {
    while (b % 5 == 0)
        b /= 5;
    while (b % 3 == 0)
        b /= 3;
    while (b % 2 == 0)
        b /= 2;
    return b;
}

int main() {
    while (true) {
        int point = 2, count = 0, num;
        cin >> num;
        if (num == 0) break;
        while (count < num) {
            if (calculate(point) == 1) {
                cout << point << " ";
                ++count;
            }
            ++point;
        }
        cout << endl;
    }
    return 0;
}