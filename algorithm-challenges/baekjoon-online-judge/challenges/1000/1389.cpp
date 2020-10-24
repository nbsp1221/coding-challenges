#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<bool>> graph(n, vector<bool>(n, false));
    int minKevinBaconNumber = INT_MAX;
    int answer = 0;

    for (int i = 0; i < m; i++) {
        int firstFriend, secondFriend;
        cin >> firstFriend >> secondFriend;

        graph[firstFriend - 1][secondFriend - 1] = true;
        graph[secondFriend - 1][firstFriend - 1] = true;
    }

    auto getKevinBaconNumber = [&](int startVertex) -> int
    {
        vector<int> degrees(n, -1);
        queue<pair<int, int>> bfsQueue;
        int result = 0;

        degrees[startVertex] = 0;
        bfsQueue.push(make_pair(startVertex, 0));

        while (!bfsQueue.empty()) {
            int nowVertex = bfsQueue.front().first;
            int nowDegree = bfsQueue.front().second;
            bfsQueue.pop();

            for (int i = 0; i < n; i++) {
                if (i == nowVertex || !graph[nowVertex][i] || degrees[i] != -1) {
                    continue;
                }

                degrees[i] = nowDegree + 1;
                bfsQueue.push(make_pair(i, nowDegree + 1));
            }
        }

        for (int i = 0; i < n; i++) {
            result += degrees[i];
        }

        return result;
    };

    for (int i = 0; i < n; i++) {
        int kevinBaconNumber = getKevinBaconNumber(i);

        if (minKevinBaconNumber > kevinBaconNumber) {
            minKevinBaconNumber = kevinBaconNumber;
            answer = i + 1;
        }
    }

    cout << answer << "\n";
    return 0;
}