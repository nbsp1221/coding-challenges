#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;

    Point() : x(0), y(0) {}
    Point(int x, int y) : x(x), y(y) {}
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> paper(n, vector<int>(m));
    int answer = 0;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            cin >> paper[y][x];
        }
    }

    vector<vector<Point>> tetrominoes = {
        { Point(0, 0), Point(1, 0), Point(2, 0), Point(3, 0) },     // I
        { Point(0, 0), Point(0, 1), Point(0, 2), Point(0, 3) },
        { Point(0, 0), Point(1, 0), Point(0, 1), Point(1, 1) },     // O
        { Point(0, 0), Point(0, 1), Point(0, 2), Point(1, 2) },     // L
        { Point(0, 0), Point(1, 0), Point(2, 0), Point(0, 1) },
        { Point(0, 0), Point(1, 0), Point(1, 1), Point(1, 2) },
        { Point(2, 0), Point(0, 1), Point(1, 1), Point(2, 1) },
        { Point(1, 0), Point(1, 1), Point(0, 2), Point(1, 2) },
        { Point(0, 0), Point(1, 0), Point(0, 1), Point(0, 2) },
        { Point(0, 0), Point(1, 0), Point(2, 0), Point(2, 1) },
        { Point(0, 0), Point(0, 1), Point(1, 1), Point(2, 1) },
        { Point(0, 0), Point(0, 1), Point(1, 1), Point(1, 2) },     // S
        { Point(1, 0), Point(2, 0), Point(0, 1), Point(1, 1) },
        { Point(1, 0), Point(0, 1), Point(1, 1), Point(0, 2) },
        { Point(0, 0), Point(1, 0), Point(1, 1), Point(2, 1) },
        { Point(0, 0), Point(1, 0), Point(2, 0), Point(1, 1) },     // T
        { Point(1, 0), Point(0, 1), Point(1, 1), Point(1, 2) },
        { Point(1, 0), Point(0, 1), Point(1, 1), Point(2, 1) },
        { Point(0, 0), Point(0, 1), Point(1, 1), Point(0, 2) }
    };

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            for (size_t i = 0; i < tetrominoes.size(); i++) {
                int sumNumbers = 0;
                bool outRange = false;

                for (int j = 0; j < 4; j++) {
                    int lx = x + tetrominoes[i][j].x;
                    int ly = y + tetrominoes[i][j].y;

                    if (lx < 0 || lx >= m || ly < 0 || ly >= n) {
                        outRange = true;
                        break;
                    }

                    sumNumbers += paper[ly][lx];
                }

                if (!outRange) {
                    answer = max(answer, sumNumbers);
                }
            }
        }
    }

    cout << answer << "\n";
    return 0;
}