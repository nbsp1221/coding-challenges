#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> dp(n, vector<int>(10));
    int answer = 0;

    for (int i = 0; i < 10; i++) {
        dp[0][i] = 1;
    }

    for (int i = 1; i < n; i++) {
        dp[i][9] = dp[i - 1][9];

        for (int j = 8; j >= 0; j--) {
            dp[i][j] = (dp[i][j + 1] + dp[i - 1][j]) % 10007;
        }
    }

    for (int i = 0; i < 10; i++) {
        answer = (answer + dp[n - 1][i]) % 10007;
    }

    cout << answer << "\n";
    return 0;
}