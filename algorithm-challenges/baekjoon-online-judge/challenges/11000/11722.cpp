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

    vector<int> arr(n), dp(n, 0);
    int answer = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] < arr[j] && dp[i] < dp[j]) dp[i] = dp[j];
        }

        dp[i]++;
        answer = max(answer, dp[i]);
    }

    cout << answer << "\n";
    return 0;
}