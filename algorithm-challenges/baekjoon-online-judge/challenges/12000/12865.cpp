#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> list(n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    for (int i = 1; i <= n; i++) {
        cin >> list[i].first >> list[i].second;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            int weight = list[i].first;
            int value = list[i].second;

            if (weight <= j) {
                dp[i][j] = max(dp[i - 1][j - weight] + value, dp[i - 1][j]);
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }

    }

    cout << dp[n][k] << "\n";
    return 0;
}
