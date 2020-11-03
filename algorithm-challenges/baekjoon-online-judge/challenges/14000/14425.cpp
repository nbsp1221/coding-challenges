#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    unordered_set<string> stringSet;
    int includeCount = 0;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        stringSet.insert(str);
    }

    for (int i = 0; i < m; i++) {
        string str;
        cin >> str;

        if (stringSet.find(str) != stringSet.end()) {
            includeCount++;
        }
    }

    cout << includeCount << "\n";
    return 0;
}