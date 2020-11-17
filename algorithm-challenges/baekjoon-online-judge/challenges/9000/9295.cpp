#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        cout << "Case " << i << ": " << (v1 + v2) << "\n";
    }

    return 0;
}