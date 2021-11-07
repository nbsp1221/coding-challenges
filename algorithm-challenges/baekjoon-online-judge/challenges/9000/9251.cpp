#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string small, big, temponary;
    cin >> small >> big;

    if (small.size() > big.size()) {
        temponary = small;
        small = big;
        big = temponary;
    }

    vector<vector<int>> lcs(big.size(), vector<int>(big.size(), 0));
    lcs[0][0] = small[0] == big[0];

    for (uint i = 1; i < small.size(); i++) {
        lcs[i][0] = lcs[i - 1][0] ? 1 : small[i] == big[0];
    }

    for (uint i = 1; i < big.size(); i++) {
        lcs[0][i] = lcs[0][i - 1] ? 1 : small[0] == big[i];
    }

    for (uint i = 1; i < small.size(); i++) {
        for (uint j = 1; j < big.size(); j++) {
            if (small[i] == big[j]) {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            }
            else {
                lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);
            }
        }
    }

    cout << lcs[small.size() - 1][big.size() - 1] << "\n";
    return 0;
}
