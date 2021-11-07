#include <iostream>
#include <functional>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<pair<int, int>>> graph(n);
    vector<bool> checker(n);
    int resultNode = 0, maxDistance = 0;

    for (int i = 0; i < n - 1; i++) {
        int first, second, weight;
        cin >> first >> second >> weight;

        first--;
        second--;

        graph[first].push_back(make_pair(second, weight));
        graph[second].push_back(make_pair(first, weight));
    }

    function<void(int, int)> dfs = [&](int node, int distance) -> void {
        if (checker[node]) {
            return;
        }

        checker[node] = true;

        if (distance > maxDistance) {
            resultNode = node;
            maxDistance = distance;
        }

        for (uint i = 0; i < graph[node].size(); i++) {
            int nextNode = graph[node][i].first;
            int nextDistance = graph[node][i].second;

            if (checker[nextNode]) {
                continue;
            }

            dfs(nextNode, distance + nextDistance);
        }
    };

    fill(checker.begin(), checker.end(), false), dfs(0, 0);
    fill(checker.begin(), checker.end(), false), dfs(resultNode, 0);

    cout << maxDistance << "\n";
    return 0;
}
