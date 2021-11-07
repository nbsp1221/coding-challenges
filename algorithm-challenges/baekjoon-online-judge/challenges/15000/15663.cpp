#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> values(n);
    vector<bool> checker(n, false);

    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    sort(values.begin(), values.end());

    function<void(const vector<int>&)> bt = [&](const vector<int>& goals) -> void {
        if (goals.size() - m == 0) {
            for (int i = 0; i < m; i++) {
                cout << goals[i] << " ";
            }

            cout << "\n";
            return;
        }

        int prevValue = -1;

        for (int i = 0; i < n; i++) {
            if (checker[i] || values[i] == prevValue) {
                continue;
            }

            vector<int> nextGoals = goals;
            nextGoals.push_back(values[i]);

            checker[i] = true;
            bt(nextGoals);
            checker[i] = false;

            prevValue = values[i];
        }
    };

    bt(vector<int>());
    return 0;
}
