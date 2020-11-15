#include <iostream>
#include <string>

using namespace std;

void testCase()
{
    string s;
    cin >> s;

    bool alphabet[26] = { 0, };
    int sumCode = 0;

    for (size_t i = 0; i < s.size(); i++) {
        alphabet[s[i] - 'A'] = true;
    }

    for (int i = 0; i < 26; i++) {
        if (!alphabet[i]) {
            sumCode += 'A' + i;
        }
    }

    cout << sumCode << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    return 0;
}