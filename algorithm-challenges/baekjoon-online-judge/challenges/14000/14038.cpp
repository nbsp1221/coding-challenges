#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int winCount = 0;

    for (int i = 0; i < 6; i++) {
        char state;
        cin >> state;

        if (state == 'W') {
            winCount++;
        }
    }

    if (winCount >= 5) {
        cout << 1 << "\n";
    }
    else if (winCount >= 3) {
        cout << 2 << "\n";
    }
    else if (winCount >= 1) {
        cout << 3 << "\n";
    }
    else {
        cout << -1 << "\n";
    }

    return 0;
}
