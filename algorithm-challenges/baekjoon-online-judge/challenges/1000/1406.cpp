#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    int n;
    cin >> str >> n;

    deque<char> cursorLeft;
    deque<char> cursorRight;
    string result;

    for (char ch : str) {
        cursorLeft.push_back(ch);
    }

    for (int i = 0; i < n; i++) {
        char command;
        cin >> command;

        if (command == 'L') {
            if (!cursorLeft.empty()) {
                cursorRight.push_front(cursorLeft.back());
                cursorLeft.pop_back();
            }
        }
        else if (command == 'D') {
            if (!cursorRight.empty()) {
                cursorLeft.push_back(cursorRight.front());
                cursorRight.pop_front();
            }
        }
        else if (command == 'B') {
            if (!cursorLeft.empty()) {
                cursorLeft.pop_back();
            }
        }
        else {
            char inputChar;
            cin >> inputChar;
            cursorLeft.push_back(inputChar);
        }
    }

    while (!cursorLeft.empty()) {
        result.push_back(cursorLeft.front());
        cursorLeft.pop_front();
    }

    while (!cursorRight.empty()) {
        result.push_back(cursorRight.front());
        cursorRight.pop_front();
    }

    cout << result << "\n";
    return 0;
}