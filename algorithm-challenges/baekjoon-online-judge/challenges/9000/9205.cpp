#include <iostream>
#include <vector>
#include <functional>
#include <cmath>

using namespace std;

struct Point
{
    int x, y;

    Point() : x(0), y(0) {}
    Point(int x, int y) : x(x), y(y) {}

    int distance(const Point& point) {
        return abs(this->x - point.x) + abs(this->y - point.y);
    }
};

void testCase()
{
    int n;
    cin >> n;

    vector<Point> points(n + 2);
    vector<vector<int>> graph(points.size(), vector<int>(points.size()));
    vector<bool> visitCheck(points.size(), false);

    for (size_t i = 0; i < points.size(); i++) {
        cin >> points[i].x >> points[i].y;
    }

    for (size_t i = 0; i < points.size(); i++) {
        for (size_t j = 0; j < points.size(); j++) {
            graph[i][j] = points[i].distance(points[j]);
        }
    }

    size_t startVertex = 0;
    size_t destinationVertex = n + 1;

    function<bool(size_t)> dfsSearch = [&](size_t vertex) -> bool
    {
        visitCheck[vertex] = true;

        if (vertex == destinationVertex) {
            return true;
        }

        for (size_t i = 0; i < points.size(); i++) {
            if (vertex == i || graph[vertex][i] > 1000 || visitCheck[i]) {
                continue;
            }

            if (dfsSearch(i)) {
                return true;
            }
        }

        return false;
    };

    cout << (dfsSearch(startVertex) ? "happy" : "sad") << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    return 0;
}