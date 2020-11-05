#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int x, answer = 0;
    cin >> x;

    while (x) {
        answer += x % 2;
        x /= 2;
    }

    cout << answer << "\n";
    return 0;
}