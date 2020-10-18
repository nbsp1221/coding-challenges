#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    unordered_map<string, string> passwords;
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string site, password;
        cin >> site >> password;
        passwords[site] = password;
    }

    for (int i = 0; i < m; i++) {
        string site;
        cin >> site;
        cout << passwords[site] << "\n";
    }

    return 0;
}