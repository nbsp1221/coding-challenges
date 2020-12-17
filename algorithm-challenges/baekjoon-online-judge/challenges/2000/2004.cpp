#include <iostream>
#include <algorithm>

using namespace std;

pair<int, int> getFactorialTwoFiveCount(int n)
{
    int twoCount = 0;
    int fiveCount = 0;

    for (int64_t i = 2; i <= n; i *= 2) {
        twoCount += n / i;
    }

    for (int64_t i = 5; i <= n; i *= 5) {
        fiveCount += n / i;
    }

    return make_pair(twoCount, fiveCount);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    if (m > n - m) {
        m = n - m;
    }

    pair<int, int> nCount = getFactorialTwoFiveCount(n);
    pair<int, int> mCount = getFactorialTwoFiveCount(m);
    pair<int, int> nmCount = getFactorialTwoFiveCount(n - m);

    nCount.first -= mCount.first + nmCount.first;
    nCount.second -= mCount.second + nmCount.second;

    cout << min(nCount.first, nCount.second) << "\n";
    return 0;
}