#include <iostream>

using namespace std;

bool containDigit(int number, int digit)
{
    while (number) {
        if (number % 10 == digit) {
            return true;
        }

        number /= 10;
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, l, answer = 1;
    cin >> n >> l;

    while (n > 0) {
        if (!containDigit(answer, l)) {
            n--;
        }

        answer++;
    }

    cout << (answer - 1) << "\n";
    return 0;
}