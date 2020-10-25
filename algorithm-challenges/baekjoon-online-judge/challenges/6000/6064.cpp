#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int m, n, x, y;
        cin >> m >> n >> x >> y;

        int lastYear = lcm(m, n);
        int nowYear = x;

        while (nowYear <= lastYear) {
            if (n == y) {
                if (nowYear % n == 0) break;
            }
            else {
                if (nowYear % n == y) break;
            }

            nowYear += m;
        }

        cout << (nowYear > lastYear ? -1 : nowYear) << "\n";
    }

    return 0;
}