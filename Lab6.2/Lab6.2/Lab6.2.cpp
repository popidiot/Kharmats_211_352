
#include <iostream>
#include <deque>

using namespace std;

bool palindrom() {
    string S;
    deque <char> check;
    cout << "Type string: ";
    cin >> S;
    for (int i = 0; i < S.size(); i++) {
        check.push_back(S[i]);
    }
    while (!check.empty()) {
        if (check.size() == 1) break;
        if (check.front() == check.back()) {
            check.pop_back();
            check.pop_front();
        }
        else {
            cout << "Not palindrom" << endl;
            return false;
        }
    }
    cout << "Palindrom" << endl;
    return true;
}


int main() {
    int N;
    while (true) {
        cout << "Type task's number: ";
        cin >> N;
        switch (N) {
        case 1:
            palindrom();
            break;
        case 2:
            break;
        case 3:
            cout << "Goodbye" << endl;
            return 0;
        default:
            cout << "Wrong input. Try again (1 - 3)." << endl;
            break;
        }
    }
    return 0;
}