#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<bool> dp(n);
    dp[0] = false;
    dp[1] = true;
    dp[2] = false;

    for (int i = 3; i < n; i++) {
        dp[i] = !(dp[i - 1] && dp[i - 3]);
    }

    cout << (dp[n - 1] ? "SK" : "CY") << "\n";
    return 0;
}