#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int scores[5] = { 0, };
    int maxScore = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            int score;
            cin >> score;
            scores[i] += score;
        }

        if (maxScore < scores[i]) {
            maxScore = scores[i];
        }
    }

    for (int i = 0; i < 5; i++) {
        if (scores[i] == maxScore) {
            cout << (i + 1) << " " << maxScore << "\n";
            break;
        }
    }

    return 0;
}