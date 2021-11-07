#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> arrA(n), arrB(n), arrC(n), arrD(n);

    for (int i = 0; i < n; i++) {
        cin >> arrA[i] >> arrB[i] >> arrC[i] >> arrD[i];
    }

    vector<int> arrAB, arrCD;
    uint64_t zeroCount = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arrAB.push_back(arrA[i] + arrB[j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arrCD.push_back(arrC[i] + arrD[j]);
        }
    }

    sort(arrAB.begin(), arrAB.end());
    sort(arrCD.begin(), arrCD.end());

    for (uint i = 0; i < arrAB.size(); i++) {
        zeroCount += upper_bound(arrCD.begin(), arrCD.end(), -arrAB[i]) - lower_bound(arrCD.begin(), arrCD.end(), -arrAB[i]);
    }

    cout << zeroCount << "\n";
    return 0;
}
