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

    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());

    function<void(const vector<int>&, int)> bt = [&](const vector<int>& goals, int startIndex) -> void {
        if (goals.size() - m == 0) {
            for (int i = 0; i < m; i++) {
                cout << goals[i] << " ";
            }

            cout << "\n";
            return;
        }

        for (uint i = startIndex; i < values.size(); i++) {
            vector<int> nextGoals = goals;
            nextGoals.push_back(values[i]);

            bt(nextGoals, i);
        }
    };

    bt(vector<int>(), 0);
    return 0;
}
