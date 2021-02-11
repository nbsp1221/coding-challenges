#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    bool paper[100][100] = { false, };
    int darkAreaCount = 0;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int startX, startY;
        cin >> startX >> startY;

        for (int y = startY; y < startY + 10; y++) {
            for (int x = startX; x < startX + 10; x++) {
                paper[y][x] = true;
            }
        }
    }

    for (int y = 0; y < 100; y++) {
        for (int x = 0; x < 100; x++) {
            darkAreaCount += paper[y][x];
        }
    }

    cout << darkAreaCount << "\n";
    return 0;
}