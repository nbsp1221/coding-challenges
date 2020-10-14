#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int result;
    cin >> result;

    bool negative = false;
    char op;
    int number;

    while (cin >> op >> number) {
        if (op == '+') {
            result += negative ? -number : number;
        }
        else if (op == '-') {
            negative = true;
            result -= number;
        }
        else {
            throw "It's an unexpected operator.";
        }
    }

    cout << result << "\n";
    return 0;
}