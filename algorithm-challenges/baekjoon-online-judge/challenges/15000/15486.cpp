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

    vector<int> term(n);
    vector<int> price(n);

    for (int i = 0; i < n; i++) {
        cin >> term[i] >> price[i];
    }

    vector<int> dp(n + 1, 0);
    int maxPrice = 0;

    for (int i = n - 1; i >= 0; i--) {
        int endTermIndex = i + term[i];

        if (endTermIndex > n) {
            dp[i] = dp[i + 1];
        }
        else if (endTermIndex < n) {
            dp[i] = max(price[i] + dp[endTermIndex], dp[i + 1]);
        }
        else {
            dp[i] = max(price[i], dp[i + 1]);
        }

        maxPrice = max(maxPrice, dp[i]);
    }

    cout << maxPrice << "\n";
    return 0;
}