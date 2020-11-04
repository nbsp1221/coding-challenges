#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int e, s, m, answer = 1;
    cin >> e >> s >> m;

    while (e != 1 || s != 1 || m != 1) {
        e--;
        s--;
        m--;
        answer++;

        if (e == 0) e = 15;
        if (s == 0) s = 28;
        if (m == 0) m = 19;
    }

    cout << answer << "\n";
    return 0;
}