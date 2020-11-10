#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;

    vector<int> sequence(1, 1);
    int sumRange = 0;

    while (sequence.size() < 1000) {
        int lastNumber = sequence.back();

        for (int i = 0; i <= lastNumber; i++) {
            sequence.push_back(lastNumber + 1);
        }
    }

    for (int i = a - 1; i < b; i++) {
        sumRange += sequence[i];
    }

    cout << sumRange << "\n";
    return 0;
}