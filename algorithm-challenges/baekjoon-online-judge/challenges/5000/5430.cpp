#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        string functions;
        int n;
        char trash;
        cin >> functions >> n >> trash;

        deque<int> intArray;
        bool isReversed = false;
        bool isError = false;

        for (int i = 0; i < n; i++) {
            int value;
            cin >> value >> trash;
            intArray.push_back(value);
        }

        if (n == 0) {
            cin >> trash;
        }

        for (auto it = functions.begin(); it != functions.end(); it++) {
            if (*it == 'R') {
                isReversed = !isReversed;
            }
            else {
                if (intArray.empty()) {
                    isError = true;
                    break;
                }

                if (isReversed) {
                    intArray.pop_back();
                }
                else {
                    intArray.pop_front();
                }
            }
        }

        if (isError) {
            cout << "error" << "\n";
        }
        else {
            cout << "[";

            if (isReversed) {
                for (auto it = intArray.rbegin(); it != intArray.rend(); it++) {
                    cout << *it;
                    if (it + 1 != intArray.rend()) cout << ",";
                }
            }
            else {
                for (auto it = intArray.begin(); it != intArray.end(); it++) {
                    cout << *it;
                    if (it + 1 != intArray.end()) cout << ",";
                }
            }

            cout << "]" << "\n";
        }
    }

    return 0;
}