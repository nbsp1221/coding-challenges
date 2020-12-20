#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<bool> table(n + 1, true);
    table[0] = false;
    table[1] = false;

    for (int i = 2; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            if (!table[j]) {
                continue;
            }

            table[j] = false;
            k--;

            if (k == 0) {
                cout << j << "\n";
                return 0;
            }
        }
    }

    return 0;
}