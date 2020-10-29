#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void testCase()
{
    int n;
    cin >> n;

    vector<vector<int>> stickers(2, vector<int>(n));
    vector<vector<int>> dp(2, vector<int>(n));
    int maxScoreSum = 0;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cin >> stickers[i][j];
        }
    }

    dp[0][0] = stickers[0][0];
    dp[1][0] = stickers[1][0];

    if (n >= 2) {
        dp[0][1] = dp[1][0] + stickers[0][1];
        dp[1][1] = dp[0][0] + stickers[1][1];

        for (int i = 2; i < n; i++) {
            dp[0][i] = max(max(dp[0][i - 2], dp[1][i - 2]), dp[1][i - 1]) + stickers[0][i];
            dp[1][i] = max(max(dp[0][i - 2], dp[1][i - 2]), dp[0][i - 1]) + stickers[1][i];
        }
    }

    for (int i = 0; i < n; i++) {
        maxScoreSum = max(maxScoreSum, dp[0][i]);
        maxScoreSum = max(maxScoreSum, dp[1][i]);
    }

    cout << maxScoreSum << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    return 0;
}