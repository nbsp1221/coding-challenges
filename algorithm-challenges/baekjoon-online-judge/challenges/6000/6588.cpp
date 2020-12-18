#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    vector<bool> isPrimeNumber(1000001, true);
    isPrimeNumber[0] = false;
    isPrimeNumber[1] = false;

    for (size_t i = 2; i * i < isPrimeNumber.size(); i++) {
        if (isPrimeNumber[i]) {
            for (size_t j = i * i; j < isPrimeNumber.size(); j += i) {
                isPrimeNumber[j] = false;
            }
        }
    }

    while (true) {
        int n;
        cin >> n;

        if (n == 0) {
            break;
        }

        for (int i = 3; i < n; i += 2) {
            if (isPrimeNumber[i] && isPrimeNumber[n - i]) {
                cout << n << " = " << i << " + " << n - i << "\n";
                break;
            }
        }
    }

    return 0;
}