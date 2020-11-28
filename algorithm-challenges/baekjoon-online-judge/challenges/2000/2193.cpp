#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    if (n <= 2) {
        cout << 1 << "\n";
    }
    else {
        vector<long long> dp(n - 1);
        dp[1] = 2;
        dp[2] = 3;

        for (int i = 3; i <= n - 2; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        cout << dp[n - 2] << "\n";
    }

    return 0;
}