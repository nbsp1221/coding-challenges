#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

bool testCase()
{
    int n;
    cin >> n;

    if (n == 0) {
        return false;
    }

    stack<pair<int, int>> st;
    long long answer = 0;

    for (int i = 0; i <= n; i++) {
        int height = 0;
        int startIndex = i;

        if (i < n) {
            cin >> height;
        }

        while (!st.empty() && st.top().second > height) {
            startIndex = st.top().first;
            answer = max(answer, (long long)(i - startIndex) * st.top().second);
            st.pop();
        }

        st.push(make_pair(startIndex, height));
    }

    cout << answer << "\n";
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        if (!testCase()) break;
    }

    return 0;
}