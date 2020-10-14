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

    vector<int> durationTimes(n);
    int answer = 0;

    for (int i = 0; i < n; i++) {
        cin >> durationTimes[i];
    }

    sort(durationTimes.begin(), durationTimes.end());

    for (int i = 0; i < n; i++) {
        answer += durationTimes[i] * (n - i);
    }

    cout << answer << "\n";
    return 0;
}