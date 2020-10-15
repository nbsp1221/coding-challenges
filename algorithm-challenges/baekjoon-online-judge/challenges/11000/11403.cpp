#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    vector<bool> visitCheck(n);
    bool existsPathToStart;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    function<void(int, int)> dfsSearch = [&](int startVertex, int nowVertex) -> void
    {
        visitCheck[nowVertex] = true;

        if (nowVertex != startVertex && graph[nowVertex][startVertex]) {
            existsPathToStart = true;
        }

        for (int i = 0; i < n; i++) {
            if (i == nowVertex || !graph[nowVertex][i] || visitCheck[i]) {
                continue;
            }

            dfsSearch(startVertex, i);
        }
    };

    for (int i = 0; i < n; i++) {
        visitCheck.assign(n, false);
        existsPathToStart = false;

        dfsSearch(i, i);
        visitCheck[i] = existsPathToStart;

        for (int j = 0; j < n; j++) {
            cout << visitCheck[j] << " ";
        }

        cout << "\n";
    }

    return 0;
}