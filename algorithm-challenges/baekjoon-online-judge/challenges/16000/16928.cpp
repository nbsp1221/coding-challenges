#include <iostream>
#include <queue>

using namespace std;

class QueueInfo {
public:
    int location;
    int diceCount;

public:
    QueueInfo(int location, int diceCount) : location(location), diceCount(diceCount) {}
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    queue<QueueInfo> bfsQueue;
    bool bfsChecker[101] = { false, };
    int jumpInfo[101] = { 0, };
    int minDiceCount;

    for (int i = 0; i < n + m; i++) {
        int from, to;
        cin >> from >> to;
        jumpInfo[from] = to;
    }

    bfsQueue.push(QueueInfo(1, 0));

    while (!bfsQueue.empty()) {
        QueueInfo queueInfo = bfsQueue.front();
        bfsQueue.pop();

        int location = queueInfo.location;
        int diceCount = queueInfo.diceCount;

        if (bfsChecker[location]) {
            continue;
        }

        bfsChecker[location] = true;

        if (location == 100) {
            minDiceCount = diceCount;
            break;
        }

        for (int i = location; i <= location + 6; i++) {
            if (i > 100 || bfsChecker[i]) {
                continue;
            }

            bfsQueue.push(QueueInfo(jumpInfo[i] ? jumpInfo[i] : i, diceCount + 1));
        }
    }

    cout << minDiceCount << "\n";
    return 0;
}
