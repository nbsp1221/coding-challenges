#include <iostream>
#include <string>
#include <stack>

#define OPEN_ROUND -1
#define CLOSE_ROUND -2
#define OPEN_SQUARE -3
#define CLOSE_SQUARE -4

using namespace std;

int getBracketCode(char bracketCharacter)
{
    switch (bracketCharacter) {
        case '(': return OPEN_ROUND;
        case ')': return CLOSE_ROUND;
        case '[': return OPEN_SQUARE;
        case ']': return CLOSE_SQUARE;
        default: throw "Unexpected the bracket.";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string inputValue;
    cin >> inputValue;

    stack<int> st;
    int answer = 0;

    for (char ch : inputValue) {
        int bracketCode = getBracketCode(ch);
        int number = 0;

        if (bracketCode == OPEN_ROUND || bracketCode == OPEN_SQUARE) {
            st.push(bracketCode);
            continue;
        }

        while (!st.empty() && st.top() >= 0) {
            number += st.top();
            st.pop();
        }

        if (st.empty()) {
            break;
        }

        if (bracketCode == CLOSE_ROUND && st.top() == OPEN_ROUND) {
            st.pop();
            st.push(number == 0 ? 2 : number * 2);
        }
        else if (bracketCode == CLOSE_SQUARE && st.top() == OPEN_SQUARE) {
            st.pop();
            st.push(number == 0 ? 3 : number * 3);
        }
        else {
            break;
        }
    }

    while (!st.empty()) {
        if (st.top() < 0) {
            cout << 0 << "\n";
            return 0;
        }

        answer += st.top();
        st.pop();
    }

    cout << answer << "\n";
    return 0;
}