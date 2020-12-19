#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<bool> isPrimeNumber(7368788, true);
    isPrimeNumber[0] = false;
    isPrimeNumber[1] = false;

    for (size_t i = 2; i * i < isPrimeNumber.size(); i++) {
        if (isPrimeNumber[i]) {
            for (size_t j = i * i; j < isPrimeNumber.size(); j += i) {
                isPrimeNumber[j] = false;
            }
        }
    }

    int k;
    cin >> k;

    for (size_t i = 2; i < isPrimeNumber.size(); i++) {
        if (isPrimeNumber[i]) {
            k--;
        }

        if (k == 0) {
            cout << i << "\n";
            break;
        }
    }

    return 0;
}