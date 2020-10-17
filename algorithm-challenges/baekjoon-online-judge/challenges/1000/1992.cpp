#include <iostream>
#include <string>
#include <vector>
#include <functional>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<vector<char>> image(n, vector<char>(n));

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> image[y][x];
        }
    }

    function<string(int, int, int)> solve = [&](int left, int top, int length) -> string
    {
        for (int y = top; y < top + length; y++) {
            for (int x = left; x < left + length; x++) {
                if (image[top][left] != image[y][x]) {
                    length /= 2;

                    string topLeft = solve(left, top, length);
                    string topRight = solve(left + length, top, length);
                    string bottomLeft = solve(left, top + length, length);
                    string bottomRight = solve(left + length, top + length, length);

                    return "(" + topLeft + topRight + bottomLeft + bottomRight + ")";
                }
            }
        }

        return string(1, image[top][left]);
    };

    cout << solve(0, 0, n) << "\n";
    return 0;
}