#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string bowls;
    int height = 10;
    cin >> bowls;

    for (size_t i = 0; i < bowls.size() - 1; i++) {
        height += bowls[i] == bowls[i + 1] ? 5 : 10;
    }

    cout << height << "\n";
    return 0;
}