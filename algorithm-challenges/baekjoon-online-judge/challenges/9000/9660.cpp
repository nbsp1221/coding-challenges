#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    bool gameState[7] = {
        true, false, true, true, true, true, false
    };

    long long n;
    cin >> n;
    cout << (gameState[(n - 1) % 7] ? "SK" : "CY") << "\n";

    return 0;
}