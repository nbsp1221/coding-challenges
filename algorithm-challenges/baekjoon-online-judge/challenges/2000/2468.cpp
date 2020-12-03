#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

int getSafeArea(vector<vector<int>> area, int floodedHeight)
{
    int n = static_cast<int>(area.size());
    int safeArea = 0;

    function<void(int, int)> dfsSearch = [&](int x, int y) -> void {
        area[y][x] = -1;

        int dx[4] = { 0, 0, -1, 1 };
        int dy[4] = { -1, 1, 0, 0 };

        for (int i = 0; i < 4; i++) {
            int lx = x + dx[i];
            int ly = y + dy[i];

            if (lx < 0 || lx >= n || ly < 0 || ly >= n) {
                continue;
            }

            if (area[ly][lx] <= floodedHeight) {
                continue;
            }

            dfsSearch(lx, ly);
        }
    };

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (area[y][x] <= floodedHeight) {
                continue;
            }

            dfsSearch(x, y);
            safeArea++;
        }
    }

    return safeArea;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> area(n, vector<int>(n));
    int minHeight = 100, maxHeight = 0;
    int maxArea = 1;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> area[y][x];

            minHeight = min(minHeight, area[y][x]);
            maxHeight = max(maxHeight, area[y][x]);
        }
    }

    for (int i = minHeight; i < maxHeight; i++) {
        maxArea = max(maxArea, getSafeArea(area, i));
    }

    cout << maxArea << "\n";
    return 0;
}