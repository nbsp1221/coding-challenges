#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;
    cout << (n % 2 ? "SK" : "CY") << "\n";

    return 0;
}