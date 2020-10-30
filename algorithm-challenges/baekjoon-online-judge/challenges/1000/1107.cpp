#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

int getDigitLength(bool* checkBrokenButton, int channel)
{
    if (channel == 0) {
        return checkBrokenButton[0] ? -1 : 1;
    }

    int digitLength = 0;

    while (channel) {
        if (checkBrokenButton[channel % 10]) {
            return -1;
        }

        digitLength++;
        channel /= 10;
    }

    return digitLength;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    bool checkBrokenButton[10] = { 0, };
    int answer = abs(n - 100);

    for (int i = 0; i < m; i++) {
        int brokenButton;
        cin >> brokenButton;
        checkBrokenButton[brokenButton] = true;
    }

    for (int i = 0; i <= 1000000; i++) {
        int digitLength = getDigitLength(checkBrokenButton, i);

        if (digitLength != -1) {
            answer = min(answer, abs(n - i) + digitLength);
        }
    }

    cout << answer << "\n";
    return 0;
}