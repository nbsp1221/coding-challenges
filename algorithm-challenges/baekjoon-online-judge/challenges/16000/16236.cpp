#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Point {
public:
    int x;
    int y;

public:
    Point(int x, int y) : x(x), y(y) {}
};

using QueueInfo = pair<Point, int>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> map(n, vector<int>(n));
    int sharkSize = 2;
    int eatenFishCount = 0;
    int answer = 0;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> map[y][x];
        }
    }

    while (true) {
        Point sharkPoint = Point(-1, -1);

        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                if (map[y][x] == 9) sharkPoint = Point(x, y);
            }
        }

        queue<QueueInfo> bfsQueue;
        vector<QueueInfo> candidates;
        vector<vector<bool>> checker(n, vector<bool>(n, false));

        bfsQueue.push(make_pair(sharkPoint, 0));

        while (!bfsQueue.empty()) {
            QueueInfo queueInfo = bfsQueue.front();
            bfsQueue.pop();

            int x = queueInfo.first.x;
            int y = queueInfo.first.y;
            int elapsedTime = queueInfo.second;

            if (checker[y][x]) {
                continue;
            }

            checker[y][x] = true;

            if (map[y][x] > 0 && map[y][x] <= 6 && map[y][x] < sharkSize) {
                candidates.push_back(make_pair(Point(x, y), elapsedTime));
                continue;
            }

            int dx[4] = { 0, 0, -1, 1 };
            int dy[4] = { -1, 1, 0, 0 };

            for (int i = 0; i < 4; i++) {
                int fx = x + dx[i];
                int fy = y + dy[i];

                if (fx < 0 || fx >= n || fy < 0 || fy >= n) {
                    continue;
                }

                if (checker[fy][fx] || map[fy][fx] > sharkSize) {
                    continue;
                }

                bfsQueue.push(make_pair(Point(fx, fy), elapsedTime + 1));
            }
        }

        if (candidates.empty()) {
            break;
        }

        sort(candidates.begin(), candidates.end(), [&](QueueInfo left, QueueInfo right) -> bool {
            if (left.second == right.second) {
                if (left.first.y == right.first.y) {
                    return left.first.x < right.first.x;
                }
                else {
                    return left.first.y < right.first.y;
                }
            }
            else {
                return left.second < right.second;
            }
        });

        map[sharkPoint.y][sharkPoint.x] = 0;
        map[candidates[0].first.y][candidates[0].first.x] = 9;
        eatenFishCount++;
        answer += candidates[0].second;

        if (eatenFishCount == sharkSize) {
            sharkSize++;
            eatenFishCount = 0;
        }
    }

    cout << answer << "\n";
    return 0;
}
