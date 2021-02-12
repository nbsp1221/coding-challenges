#include <iostream>
#include <functional>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> graph(n);
    vector<bool> visitChecker(n);
    vector<int> parentInfo(n);

    for (int i = 0; i < n - 1; i++) {
        int vertex1, vertex2;
        cin >> vertex1 >> vertex2;

        vertex1--;
        vertex2--;

        graph[vertex1].push_back(vertex2);
        graph[vertex2].push_back(vertex1);
    }

    function<void(int)> dfsSearch = [&](int vertex) -> void {
        visitChecker[vertex] = true;

        for (int nextVertex : graph[vertex]) {
            if (visitChecker[nextVertex]) {
                continue;
            }

            parentInfo[nextVertex] = vertex;
            dfsSearch(nextVertex);
        }
    };

    dfsSearch(0);

    for (int i = 1; i < n; i++) {
        cout << (parentInfo[i] + 1) << "\n";
    }

    return 0;
}