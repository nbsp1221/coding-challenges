#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    bool gameState[5] = {
        true, false, true, true, false
    };

    long long n;
    cin >> n;
    cout << (gameState[(n - 1) % 5] ? "SK" : "CY") << "\n";

    return 0;
}