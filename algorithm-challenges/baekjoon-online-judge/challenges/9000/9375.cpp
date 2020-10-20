#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        unordered_map<string, int> clothes;
        int answer = 1;

        for (int i = 0; i < n; i++) {
            string name, kind;
            cin >> name >> kind;

            if (clothes.find(kind) == clothes.end()) {
                clothes[kind] = 1;
            }
            else {
                clothes[kind]++;
            }
        }

        for (auto it = clothes.begin(); it != clothes.end(); it++) {
            answer *= (it->second + 1);
        }

        cout << (answer - 1) << "\n";
    }

    return 0;
}