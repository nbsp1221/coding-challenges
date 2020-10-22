#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    string s;
    cin >> n >> m >> s;

    int nowMaxCount = -1;
    int answer = 0;

    for (int i = 0; i < m - 1; i++) {
        if (nowMaxCount == -1) {
            if (s[i] == 'I') nowMaxCount = 0;
        }
        else {
            if (s[i] == 'O' && s[i + 1] == 'I') {
                nowMaxCount++;
                i++;

                if (nowMaxCount >= n) {
                    answer++;
                }
            }
            else {
                nowMaxCount = s[i] == 'I' ? 0 : -1;
            }
        }
    }

    cout << answer << "\n";
    return 0;
}