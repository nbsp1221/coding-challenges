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

    int vertexLength, edgeLength;
    cin >> vertexLength >> edgeLength;

    int startVertex;
    cin >> startVertex, startVertex--;

    vector<vector<pair<int, int>>> graph(vertexLength);
    vector<int> distanceTable(vertexLength, infinity);

    for (int i = 0; i < edgeLength; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;

        graph[--from].push_back(make_pair(--to, weight));
    }

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

        for (uint i = 0; i < graph[vertex].size(); i++) {
            int targetVertex = graph[vertex][i].first;
            int targetDistance = distance + graph[vertex][i].second;

            if (targetDistance < distanceTable[targetVertex]) {
                distanceTable[targetVertex] = targetDistance;
                pq.push(make_pair(targetVertex, targetDistance));
            }
        }
    }

    for (int i = 0; i < vertexLength; i++) {
        if (distanceTable[i] == infinity) {
            cout << "INF" << "\n";
        }
        else {
            cout << distanceTable[i] << "\n";
        }
    }

    return 0;
}
