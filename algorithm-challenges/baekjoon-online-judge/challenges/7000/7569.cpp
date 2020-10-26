#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Point
{
    int x, y, z;

    Point() : x(0), y(0), z(0) {}
    Point(int x, int y, int z) : x(x), y(y), z(z) {}
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n, h;
    cin >> m >> n >> h;

    vector<vector<vector<int>>> tomatoes(h, vector<vector<int>>(n, vector<int>(m)));
    queue<pair<Point, int>> bfsQueue;

    for (int z = 0; z < h; z++) {
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                cin >> tomatoes[z][y][x];

                if (tomatoes[z][y][x] == 1) {
                    bfsQueue.push(make_pair(Point(x, y, z), 0));
                }
            }
        }
    }

    int dx[6] = { 0, 0, -1, 1, 0, 0 };
    int dy[6] = { -1, 1, 0, 0, 0, 0 };
    int dz[6] = { 0, 0, 0, 0, -1, 1 };
    int maxElapsedTime = 0;
    bool allClear = true;

    while (!bfsQueue.empty()) {
        pair<Point, int> bfsInfo = bfsQueue.front();
        bfsQueue.pop();

        int elapsedTime = bfsInfo.second;
        maxElapsedTime = max(maxElapsedTime, elapsedTime);

        for (int i = 0; i < 6; i++) {
            int x = bfsInfo.first.x + dx[i];
            int y = bfsInfo.first.y + dy[i];
            int z = bfsInfo.first.z + dz[i];

            if (x < 0 || x >= m || y < 0 || y >= n || z < 0 || z >= h) {
                continue;
            }

            if (tomatoes[z][y][x] == 0) {
                bfsQueue.push(make_pair(Point(x, y, z), elapsedTime + 1));
                tomatoes[z][y][x] = 1;
            }
        }
    }

    for (int z = 0; z < h; z++) {
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if (tomatoes[z][y][x] == 0) allClear = false;
            }
        }
    }

    cout << (allClear ? maxElapsedTime : -1) << "\n";
    return 0;
}