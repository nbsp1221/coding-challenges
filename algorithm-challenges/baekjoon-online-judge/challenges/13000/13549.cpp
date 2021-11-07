#include <iostream>
#include <limits>
#include <vector>
#include <deque>

using namespace std;

const int infinity = numeric_limits<int>::max();

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> table(max(n, k) + 2, infinity);
    deque<pair<int, int>> dq;

    dq.push_back(make_pair(n, 0));

    while (!dq.empty()) {
        pair<int, int> queueInfo = dq.front();
        dq.pop_front();

        int node = queueInfo.first;
        int time = queueInfo.second;

        if (time > table[node]) {
            continue;
        }

        if (node == k) {
            table[node] = min(table[node], time);
        }

        int nextNodes[3] = { node - 1, node + 1, node * 2 };
        int nextTimes[3] = { time + 1, time + 1, time };

        for (int i = 0; i < 3; i++) {
            int nextNode = nextNodes[i];
            int nextTime = nextTimes[i];

            if (nextNode < 0 || nextNode > static_cast<int>(table.size()) - 1) {
                continue;
            }

            if (nextTime < table[nextNode]) {
                table[nextNode] = nextTime;

                if (nextTime == time) {
                    dq.push_front(make_pair(nextNode, nextTime));
                }
                else {
                    dq.push_back(make_pair(nextNode, nextTime));
                }
            }
        }
    }

    cout << table[k] << "\n";
    return 0;
}
