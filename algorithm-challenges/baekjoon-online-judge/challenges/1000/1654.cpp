#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int nowCount, needCount;
    cin >> nowCount >> needCount;

    vector<int> cables(nowCount);
    uint lowerBound = 1, upperBound = 0;
    int answer = 0;

    for (int i = 0; i < nowCount; i++) {
        cin >> cables[i];

        if (upperBound < (uint)cables[i]) {
            upperBound = cables[i];
        }
    }

    while (lowerBound <= upperBound) {
        int mid = (lowerBound + upperBound) >> 1;
        int cutCount = 0;

        for (int i = 0; i < nowCount; i++) {
            cutCount += cables[i] / mid;
        }

        if (cutCount >= needCount) {
            lowerBound = mid + 1;
            answer = mid;
        }
        else {
            upperBound = mid - 1;
        }
    }

    cout << answer << "\n";
    return 0;
}