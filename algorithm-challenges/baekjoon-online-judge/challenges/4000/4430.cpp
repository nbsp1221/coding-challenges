#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

class Elephant {
public:
    int number;
    int weight;
    int iq;

public:
    Elephant(int number, int weight, int iq) : number(number), weight(weight), iq(iq) {}
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<Elephant> elephants;

    for (int i = 1; true; i++) {
        int weight, iq;
        cin >> weight >> iq;

        if (cin.fail() || cin.eof()) {
            break;
        }

        elephants.push_back(Elephant(i, weight, iq));
    }

    sort(elephants.begin(), elephants.end(), [](Elephant left, Elephant right) -> bool {
        return left.iq > right.iq;
    });

    vector<int> dp(elephants.size(), 0);
    vector<vector<int>> sequences(elephants.size());
    int largestLength = 0;

    dp[0] = 1;
    sequences[0].push_back(elephants[0].number);

    for (uint i = 1; i < elephants.size(); i++) {
        for (uint j = 0; j < i; j++) {
            if (elephants[i].weight <= elephants[j].weight || elephants[i].iq >= elephants[j].iq) {
                continue;
            }

            if (dp[i] < dp[j]) {
                dp[i] = dp[j];

                sequences[i] = sequences[j];
                sequences[i].push_back(elephants[i].number);
            }
        }

        if (dp[i] == 0) {
            sequences[i].push_back(elephants[i].number);
        }

        dp[i]++;
        largestLength = max(largestLength, dp[i]);
    }

    cout << largestLength << "\n";

    for (uint i = 0; i < elephants.size(); i++) {
        if (dp[i] == largestLength) {
            for (uint j = 0; j < sequences[i].size(); j++) {
                cout << sequences[i][j] << "\n";
            }

            break;
        }
    }

    return 0;
}
