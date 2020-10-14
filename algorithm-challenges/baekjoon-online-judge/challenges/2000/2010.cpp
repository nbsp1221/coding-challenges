#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, outletCount = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        outletCount += value;
    }

    cout << (outletCount - n + 1) << "\n";
    return 0;
}