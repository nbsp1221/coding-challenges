#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> inputs;
    int maxInput = 0;

    while (true) {
        int n;
        cin >> n;

        if (cin.fail() || cin.eof()) {
            break;
        }

        inputs.push_back(n);
        maxInput = max(maxInput, n);
    }

    vector<uint64_t> dp(maxInput + 1);
    dp[1] = 1;

    for (int i = 2; i <= maxInput; i++) {
        int factor = i - round(sqrt(i * 2 + 1)) + 1;
        dp[i] = dp[factor] * 2 + (1ull << (i - factor)) - 1;
    }

    for (auto i = 0u; i < inputs.size(); i++) {
        cout << "Case " << (i + 1) << ": " << dp[inputs[i]] << "\n";
    }

    return 0;
}
