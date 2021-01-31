#include <iostream>
#include <queue>

using namespace std;

int getMinCountForCalculation(int startValue, int endValue)
{
    if (endValue % 2 == 1 && endValue % 10 >= 3) {
        return -1;
    }

    queue<pair<int, int>> bfsQueue;
    bfsQueue.push(make_pair(startValue, 1));

    while (!bfsQueue.empty()) {
        int nowValue = bfsQueue.front().first;
        int nowCount = bfsQueue.front().second;
        bfsQueue.pop();

        if (nowValue == endValue) {
            return nowCount;
        }

        if (nowValue * 2 <= endValue) {
            bfsQueue.push(make_pair(nowValue * 2, nowCount + 1));
        }

        if (nowValue < 100000000) {
            bfsQueue.push(make_pair(nowValue * 10 + 1, nowCount + 1));
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int startValue, endValue;
    cin >> startValue >> endValue;
    cout << getMinCountForCalculation(startValue, endValue) << "\n";

    return 0;
}