#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<string> names(n);
    bool isIncreasing = true;
    bool isDecreasing = true;

    for (int i = 0; i < n; i++) {
        cin >> names[i];
    }

    for (int i = 1; i < n; i++) {
        if (names[i - 1] < names[i]) isDecreasing = false;
        if (names[i - 1] > names[i]) isIncreasing = false;
    }

    if (isIncreasing) {
        cout << "INCREASING" << "\n";
    }
    else if (isDecreasing) {
        cout << "DECREASING" << "\n";
    }
    else {
        cout << "NEITHER" << "\n";
    }

    return 0;
}