#include <iostream>
#include <deque>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    deque<int> circularQueue;
    int shiftCount = 0;

    for (int i = 0; i < n; i++) {
        circularQueue.push_back(i + 1);
    }

    for (int i = 0; i < m; i++) {
        size_t index;
        int target;
        cin >> target;

        for (size_t j = 0; j < circularQueue.size(); j++) {
            if (target == circularQueue[j]) {
                index = j;
                break;
            }
        }

        while (circularQueue.front() != target) {
            if (index <= circularQueue.size() / 2) {
                circularQueue.push_back(circularQueue.front());
                circularQueue.pop_front();
            }
            else {
                circularQueue.push_front(circularQueue.back());
                circularQueue.pop_back();
            }

            shiftCount++;
        }

        circularQueue.pop_front();
    }

    cout << shiftCount << "\n";
    return 0;
}