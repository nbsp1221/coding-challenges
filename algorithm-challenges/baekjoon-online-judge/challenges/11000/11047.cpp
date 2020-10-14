#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> coins(n);
    int answer = 0;

    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    for (int i = n - 1; i >= 0; i--) {
        answer += k / coins[i];
        k %= coins[i];
    }

    cout << answer << "\n";
    return 0;
}