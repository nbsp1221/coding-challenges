#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> dp(n + 1, 0);
    dp[2] = 3;
    dp[4] = 11;

    for (int i = 6; i <= n; i += 2) {
        dp[i] = dp[i - 2] * 3 + 2;

        for (int j = 4; j <= i - 2; j += 2) {
            dp[i] += dp[i - j] * 2;
        }
    }

    cout << dp[n] << "\n";
    return 0;
}