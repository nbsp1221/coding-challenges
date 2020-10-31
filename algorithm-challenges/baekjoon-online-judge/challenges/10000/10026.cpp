#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int getAreaSize(vector<vector<char>> image)
{
    int imageSize = static_cast<int>(image.size());
    int areaSize = 0;

    function<void(int, int)> dfsSearch = [&](int curX, int curY) -> void
    {
        char color = image[curY][curX];
        image[curY][curX] = -1;

        int dx[4] = { 0, 0, -1, 1 };
        int dy[4] = { -1, 1, 0, 0 };

        for (int i = 0; i < 4; i++) {
            int x = curX + dx[i];
            int y = curY + dy[i];

            if (x < 0 || x >= imageSize || y < 0 || y >= imageSize || image[y][x] != color) {
                continue;
            }

            dfsSearch(x, y);
        }
    };

    for (int y = 0; y < imageSize; y++) {
        for (int x = 0; x < imageSize; x++) {
            if (image[y][x] != -1) {
                dfsSearch(x, y);
                areaSize++;
            }
        }
    }

    return areaSize;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<char>> normalImage(n, vector<char>(n));
    vector<vector<char>> weaknessImage(n, vector<char>(n));

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> normalImage[y][x];
            weaknessImage[y][x] = normalImage[y][x] == 'G' ? 'R' : normalImage[y][x];
        }
    }

    cout << getAreaSize(normalImage) << " ";
    cout << getAreaSize(weaknessImage) << "\n";

    return 0;
}