#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, answer = 0;
    cin >> n;

    for (int i = 2; i * i <= n; i++) {
        answer += (n - i * i) / i + 1;
    }

    answer += n;
    cout << answer << "\n";

    return 0;
}