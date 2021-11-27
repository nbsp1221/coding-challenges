#include <iostream>
#include <limits>
#include <vector>
#include <queue>

using namespace std;

const int infinity = numeric_limits<int>::max();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> timeTable(max(n, k) + 2, infinity);
    int caseCount = 0;

    queue<pair<int, int>> bfsQueue;
    bfsQueue.push(make_pair(n, 0));

    while (!bfsQueue.empty()) {
        pair<int, int> queueInfo = bfsQueue.front();
        bfsQueue.pop();

        int position = queueInfo.first;
        int time = queueInfo.second;

        if (time > timeTable[position]) {
            continue;
        }

        timeTable[position] = min(timeTable[position], time);

        if (position == k) {
            caseCount++;
        }

        int nextPositions[3] = { position - 1, position + 1, position * 2 };
        int nextTime = time + 1;

        for (int i = 0; i < 3; i++) {
            int nextPosition = nextPositions[i];

            if (nextPosition < 0 || nextPosition >= static_cast<int>(timeTable.size())) {
                continue;
            }

            if (nextTime > timeTable[nextPosition]) {
                continue;
            }

            bfsQueue.push(make_pair(nextPosition, nextTime));
        }
    }

    cout << timeTable[k] << "\n";
    cout << caseCount << "\n";

    return 0;
}
