#include <iostream>
#include <limits>
#include <vector>
#include <queue>

using namespace std;

const int infinity = numeric_limits<int>::max();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>(n, infinity));
    vector<int> distanceTable(n, infinity);

    while (m--) {
        int from, to, weight;
        cin >> from >> to >> weight;

        from--;
        to--;

        if (weight < graph[from][to]) {
            graph[from][to] = weight;
        }
    }

    int startVertex, endVertex;
    cin >> startVertex >> endVertex, startVertex--, endVertex--;

    auto compareFn = [](pair<int, int> left, pair<int, int> right) -> bool { return left.second > right.second; };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compareFn)> pq(compareFn);

    distanceTable[startVertex] = 0;
    pq.push(make_pair(startVertex, 0));

    while (!pq.empty()) {
        pair<int, int> queueInfo = pq.top();
        pq.pop();

        int vertex = queueInfo.first;
        int distance = queueInfo.second;

        if (distance > distanceTable[vertex]) {
            continue;
        }

        for (int i = 0; i < n; i++) {
            if (graph[vertex][i] == infinity) {
                continue;
            }

            if (distance + graph[vertex][i] < distanceTable[i]) {
                distanceTable[i] = distance + graph[vertex][i];
                pq.push(make_pair(i, distanceTable[i]));
            }
        }
    }

    cout << distanceTable[endVertex] << "\n";
    return 0;
}
