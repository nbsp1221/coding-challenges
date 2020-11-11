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

    vector<int> ropes(n);
    int maxWeight = 0;

    for (int i = 0; i < n; i++) {
        cin >> ropes[i];
    }

    sort(ropes.begin(), ropes.end(), greater<int>());

    for (int i = 0; i < n; i++) {
        maxWeight = max(maxWeight, ropes[i] * (i + 1));
    }

    cout << maxWeight << "\n";
    return 0;
}