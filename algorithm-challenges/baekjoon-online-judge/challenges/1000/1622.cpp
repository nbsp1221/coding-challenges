#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s1;
    string s2;

    while (getline(cin, s1), getline(cin, s2)) {
        int table1[26] = { 0, };
        int table2[26] = { 0, };

        for (auto i = 0u; i < s1.size(); i++) {
            table1[s1[i] - 97]++;
        }

        for (auto i = 0u; i < s2.size(); i++) {
            table2[s2[i] - 97]++;
        }

        for (int i = 0; i < 26; i++) {
            if (table1[i] == 0 || table2[i] == 0) {
                continue;
            }

            string result(min(table1[i], table2[i]), i + 97);
            cout << result;
        }

        cout << "\n";
    }

    return 0;
}
