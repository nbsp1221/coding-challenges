#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> prefixSums(n + 1, vector<int>(n + 1, 0));

    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= n; x++) {
            cin >> prefixSums[y][x];
            prefixSums[y][x] += prefixSums[y - 1][x] + prefixSums[y][x - 1] - prefixSums[y - 1][x - 1];
        }
    }

    while (m--) {
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;

        int answer = prefixSums[y2][x2] - (prefixSums[y2][x1 - 1] + prefixSums[y1 - 1][x2] - prefixSums[y1 - 1][x1 - 1] );
        cout << answer << "\n";
    }

    return 0;
}
