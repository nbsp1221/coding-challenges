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

    vector<int> dp(n, 0);
    int maxPrice = 0;

    for (int i = n - 1; i >= 0; i--) {
        int endTermIndex = i + term[i];

        if (endTermIndex > n) {
            continue;
        }
        else if (endTermIndex < n) {
            dp[i] = max(price[i], price[i] + *max_element(dp.begin() + endTermIndex, dp.end()));
        }
        else {
            dp[i] = price[i];
        }

        maxPrice = max(maxPrice, dp[i]);
    }

    cout << maxPrice << "\n";
    return 0;
}