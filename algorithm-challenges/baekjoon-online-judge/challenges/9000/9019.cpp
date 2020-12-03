#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

void testCase()
{
    int a, b;
    cin >> a >> b;

    char dslr[4] = { 'D', 'S', 'L', 'R' };
    pair<int, char> tree[10000];
    queue<int> bfsQueue;

    for (int i = 0; i < 10000; i++) {
        tree[i].first = -1;
    }

    bfsQueue.push(a);

    while (!bfsQueue.empty()) {
        int beforeValue = bfsQueue.front();
        bfsQueue.pop();

        if (beforeValue == b) {
            break;
        }

        for (int i = 0; i < 4; i++) {
            int afterValue;

            switch (dslr[i]) {
                case 'D':
                    afterValue = beforeValue * 2 % 10000;
                    break;

                case 'S':
                    afterValue = beforeValue == 0 ? 9999 : beforeValue - 1;
                    break;

                case 'L':
                    afterValue = beforeValue % 1000 * 10 + beforeValue / 1000;
                    break;

                case 'R':
                    afterValue = beforeValue % 10 * 1000 + beforeValue / 10;
                    break;
            }

            if (tree[afterValue].first != -1) {
                continue;
            }

            tree[afterValue].first = beforeValue;
            tree[afterValue].second = dslr[i];

            bfsQueue.push(afterValue);
        }
    }

    vector<char> result;
    int pointer = b;

    while (pointer != a) {
        result.push_back(tree[pointer].second);
        pointer = tree[pointer].first;
    }

    for (int i = static_cast<int>(result.size()) - 1; i >= 0; i--) {
        cout << result[i];
    }

    cout << "\n";
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