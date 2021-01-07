#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> targetNumbers;
vector<int> strikeCounts;
vector<int> ballCounts;

int getStrikeAndBall(int* targetDigits, int* answerDigits)
{
    int strikeCount = 0;
    int ballCount = 0;

    for (int i = 0; i < 3; i++) {
        if (targetDigits[i] == answerDigits[i]) {
            strikeCount++;
            continue;
        }

        for (int j = 0; j < 3; j++) {
            if (targetDigits[i] == answerDigits[j]) {
                ballCount++;
                break;
            }
        }
    }

    return strikeCount * 10 + ballCount;
}

bool isPossibleAnswer(int* answerDigits)
{
    for (int i = 0; i < n; i++) {
        int targetDigits[3] = { 0, };
        int targetNumber = targetNumbers[i];
        int targetIndex = 2;

        while (targetNumber) {
            targetDigits[targetIndex--] = targetNumber % 10;
            targetNumber /= 10;
        }

        int strikeAndBall = getStrikeAndBall(targetDigits, answerDigits);
        int strikeCount = strikeAndBall / 10;
        int ballCount = strikeAndBall % 10;

        if (strikeCount != strikeCounts[i] || ballCount != ballCounts[i]) {
            return false;
        }
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int answer = 0;
    cin >> n;

    targetNumbers.assign(n, 0);
    strikeCounts.assign(n, 0);
    ballCounts.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> targetNumbers[i] >> strikeCounts[i] >> ballCounts[i];
    }

    for (int i = 1; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
            for (int k = 1; k < 10; k++) {
                if (i == j || j == k || k == i) {
                    continue;
                }

                int answerDigits[3] = { i, j, k };
                answer += isPossibleAnswer(answerDigits);
            }
        }
    }

    cout << answer << "\n";
    return 0;
}
