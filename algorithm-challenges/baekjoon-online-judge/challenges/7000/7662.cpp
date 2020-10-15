#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        map<int, int> dualPriorityQueue;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            char op;
            int value;
            cin >> op >> value;

            if (op == 'I') {
                if (dualPriorityQueue.find(value) == dualPriorityQueue.end()) {
                    dualPriorityQueue[value] = 1;
                }
                else {
                    dualPriorityQueue[value]++;
                }
            }
            else {
                if (dualPriorityQueue.empty()) {
                    continue;
                }

                int minValue = dualPriorityQueue.begin()->first;
                int minCount = dualPriorityQueue.begin()->second;
                int maxValue = dualPriorityQueue.rbegin()->first;
                int maxCount = dualPriorityQueue.rbegin()->second;

                if (value == 1) {
                    if (maxCount > 1) {
                        dualPriorityQueue[maxValue]--;
                    }
                    else {
                        dualPriorityQueue.erase(maxValue);
                    }
                }
                else {
                    if (minCount > 1) {
                        dualPriorityQueue[minValue]--;
                    }
                    else {
                        dualPriorityQueue.erase(minValue);
                    }
                }
            }
        }

        if (dualPriorityQueue.empty()) {
            cout << "EMPTY" << "\n";
        }
        else {
            cout << dualPriorityQueue.rbegin()->first << " " << dualPriorityQueue.begin()->first << "\n";
        }
    }

    return 0;
}