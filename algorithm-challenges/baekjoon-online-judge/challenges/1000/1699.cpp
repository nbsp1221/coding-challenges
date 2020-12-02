#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> dp(n + 1);

    for (int i = 1; i <= n; i++) {
        dp[i] = i;
    }

    for (int i = 2; i * i <= n; i++) {
        for (int j = i * i; j <= n; j++) {
            dp[j] = min(dp[j], dp[j - i * i] + 1);
        }
    }

    cout << dp[n] << "\n";
    return 0;
}