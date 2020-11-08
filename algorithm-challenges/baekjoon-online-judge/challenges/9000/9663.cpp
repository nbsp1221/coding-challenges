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

    vector<bool> vertical(n, false);
    vector<bool> leftDiagonal(n * 2 - 1, false);
    vector<bool> rightDiagonal(n * 2 - 1, false);
    int caseNumber = 0;

    auto setQueen = [&](int x, int y, bool state) -> void {
        vertical[x] = leftDiagonal[x + y] = rightDiagonal[n - 1 - x + y] = state;
    };

    function<void(int)> findSolutions = [&](int y) -> void {
        if (y == n - 1) {
            caseNumber++;
            return;
        }

        for (int i = 0; i < n; i++) {
            if (vertical[i] || leftDiagonal[i + y + 1] || rightDiagonal[n - i + y]) {
                continue;
            }

            setQueen(i, y + 1, true);
            findSolutions(y + 1);
            setQueen(i, y + 1, false);
        }
    };

    findSolutions(-1);
    cout << caseNumber << "\n";

    return 0;
}