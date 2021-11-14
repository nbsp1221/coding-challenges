#include <iostream>
#include <limits>
#include <vector>

using namespace std;

const int infinity = numeric_limits<int>::max();

class Edge {
public:
    int from;
    int to;
    int time;

public:
    Edge(int from, int to, int time) : from(from), to(to), time(time) {}
};

void testCase()
{
    int n, r, w;
    cin >> n >> r >> w;

    vector<Edge> edges;
    vector<int> table(n, 0);

    for (int i = 0; i < r; i++) {
        int from, to, time;
        cin >> from >> to >> time;

        from--;
        to--;

        edges.push_back(Edge(from, to, time));
        edges.push_back(Edge(to, from, time));
    }

    for (int i = 0; i < w; i++) {
        int from, to, time;
        cin >> from >> to >> time;

        from--;
        to--;
        time = -time;

        edges.push_back(Edge(from, to, time));
    }

    for (int i = 0; i < n; i++) {
        for (const auto& edge : edges) {
            if (table[edge.from] + edge.time >= table[edge.to]) {
                continue;
            }

            table[edge.to] = table[edge.from] + edge.time;

            if (i == n - 1) {
                cout << "YES" << "\n";
                return;
            }
        }
    }

    cout << "NO" << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    return 0;
}
