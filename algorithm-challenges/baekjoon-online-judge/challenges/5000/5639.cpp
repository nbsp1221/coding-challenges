#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(const vector<int>& list, int startIndex, int endIndex)
{
    if (startIndex >= endIndex) {
        if (startIndex == endIndex) {
            cout << list[startIndex] << "\n";
        }

        return;
    }

    auto reference = upper_bound(list.begin() + startIndex + 1, list.begin() + endIndex + 1, list[startIndex]);
    int referenceIndex = reference - list.begin();

    solve(list, startIndex + 1, referenceIndex - 1);
    solve(list, referenceIndex, endIndex);

    cout << list[startIndex] << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int value;
    vector<int> list;

    while (cin >> value) {
        list.push_back(value);
    }

    solve(list, 0, list.size() - 1);
    return 0;
}
