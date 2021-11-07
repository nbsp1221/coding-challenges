#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <queue>

using namespace std;

const int infinity = numeric_limits<int>::max();

class Point {
public:
    int x;
    int y;

public:
    Point(int x, int y) : x(x), y(y) {}
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> map(n, vector<int>(m));
    vector<vector<int>> shortestDistance(n, vector<int>(m, infinity));
    vector<pair<Point, int>> walls;

    for (int y = 0; y < n; y++) {
        string state;
        cin >> state;

        for (int x = 0; x < m; x++) {
            map[y][x] = state[x] - '0';
        }
    }

    auto bfs = [&](const Point& startPoint, int startDistance) -> void {
        queue<pair<Point, int>> bfsQueue;
        bfsQueue.push(make_pair(startPoint, startDistance));

        while (!bfsQueue.empty()) {
            pair<Point, int> queueInfo = bfsQueue.front();
            bfsQueue.pop();

            int x = queueInfo.first.x, y = queueInfo.first.y;
            int distance = queueInfo.second;

            if (distance >= shortestDistance[y][x]) {
                continue;
            }

            if (map[y][x] != 1) {
                shortestDistance[y][x] = distance;
            }

            int dx[4] = { 0, 0, -1, 1 };
            int dy[4] = { -1, 1, 0, 0 };

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                    continue;
                }

                if (map[ny][nx] == 1) {
                    continue;
                }

                bfsQueue.push(make_pair(Point(nx, ny), distance + 1));
            }
        }
    };

    bfs(Point(0, 0), 1);

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (map[y][x] != 1) {
                continue;
            }

            int startDistance = infinity;
            int dx[4] = { 0, 0, -1, 1 };
            int dy[4] = { -1, 1, 0, 0 };

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                    continue;
                }

                startDistance = min(startDistance, shortestDistance[ny][nx]);
            }

            if (startDistance != infinity) {
                walls.push_back(make_pair(Point(x, y), startDistance + 1));
            }
        }
    }

    for (const auto& wall : walls) {
        bfs(wall.first, wall.second);
    }

    if (shortestDistance[n - 1][m - 1] == infinity) {
        cout << -1 << "\n";
    }
    else {
        cout << shortestDistance[n - 1][m - 1] << "\n";
    }

    return 0;
}
