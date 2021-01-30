#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, maxHappy = 0;
vector<int> damages;
vector<int> happies;

void bruteForceSearch(int nowIndex, int nowDamage, int nowHappy)
{
    if (nowDamage >= 100) {
        return;
    }

    maxHappy = max(maxHappy, nowHappy);

    for (int i = nowIndex + 1; i < n; i++) {
        bruteForceSearch(i, nowDamage + damages[i], nowHappy + happies[i]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    damages.resize(n);
    happies.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> damages[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> happies[i];
    }

    for (int i = 0; i < n; i++) {
        bruteForceSearch(i, damages[i], happies[i]);
    }

    cout << maxHappy << "\n";
    return 0;
}
