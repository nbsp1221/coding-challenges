#include <iostream>
#include <unordered_set>

using namespace std;

void testCase()
{
    unordered_set<int> check;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        check.insert(value);
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int value;
        cin >> value;
        cout << check.count(value) << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    return 0;
}