#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    stack <char> check;
    string input;
    cout << "Input string: ";
    cin >> input;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == '(' || input[i] == '[' || input[i] == '{') {
            check.push(input[i]);
        }
        else if (input[i] == ')' || input[i] == ']' || input[i] == '}') {
            if (check.empty()) {
                cout << "Wrong";
                return 1;
            }
            switch (input[i]) {
            case ')':
                if (check.top() == '(') check.pop();
                else {
                    cout << "Wrong";
                    return 1;
                }
                break;
            case ']':
                if (check.top() == '[') check.pop();
                else {
                    cout << "Wrong";
                    return 1;
                }
                break;
            case '}':
                if (check.top() == '{') check.pop();
                else {
                    cout << "Wrong";
                    return 1;
                }
                break;
            }
        }
    }
    cout << "Right." << endl;
    return 0;
}