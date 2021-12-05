#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> m;

    int ballPosition = 1;

    while (m--) {
        int x, y;
        cin >> x >> y;

        if (x == ballPosition || y == ballPosition) {
            ballPosition = x + y - ballPosition;
        }
    }

    cout << ballPosition << "\n";
    return 0;
}
