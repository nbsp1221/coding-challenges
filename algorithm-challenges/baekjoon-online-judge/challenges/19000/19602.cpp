#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int s, m, l;
    cin >> s >> m >> l;

    if (s + m * 2 + l * 3 >= 10) {
        cout << "happy" << "\n";
    }
    else {
        cout << "sad" << "\n";
    }

    return 0;
}
