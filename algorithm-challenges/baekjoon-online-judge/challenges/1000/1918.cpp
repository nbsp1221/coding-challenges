#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string infixNotation;
    cin >> infixNotation;

    string postfixNotation;
    stack<char> st;
    unordered_map<char, int> priority = { { '+', 1 }, { '-', 1 }, { '*', 0 }, { '/', 0 } };

    for (uint i = 0; i < infixNotation.size(); i++) {
        switch (infixNotation[i]) {
            case '+':
            case '-':
            case '*':
            case '/':
                while (!st.empty() && st.top() != '(' && priority[st.top()] <= priority[infixNotation[i]]) {
                    postfixNotation.push_back(st.top());
                    st.pop();
                }

                st.push(infixNotation[i]);
                break;

            case '(':
                st.push(infixNotation[i]);
                break;

            case ')':
                while (!st.empty() && st.top() != '(') {
                    postfixNotation.push_back(st.top());
                    st.pop();
                }

                st.pop();
                break;

            default:
                postfixNotation.push_back(infixNotation[i]);
        }
    }

    while (!st.empty()) {
        postfixNotation.push_back(st.top());
        st.pop();
    }

    cout << postfixNotation << "\n";
    return 0;
}
