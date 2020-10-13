#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, answer = 0;
    cin >> n;

    for (int i = 0; i <= n; i++) {
        int value = i;

        while (value > 0 && value % 5 == 0) {
            value /= 5;
            answer++;
        }
    }

    cout << answer << "\n";
    return 0;
}