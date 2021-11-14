#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if ((a == 8 || a == 9) && (d == 8 || d == 9) && (b == c)) {
        cout << "ignore" << "\n";
    }
    else {
        cout << "answer" << "\n";
    }

    return 0;
}
