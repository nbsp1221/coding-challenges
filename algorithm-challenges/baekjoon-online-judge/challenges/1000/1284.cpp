#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int n;
        cin >> n;

        if (n == 0) {
            break;
        }

        int width = 1;

        while (n) {
            int digit = n % 10;

            n /= 10;
            width += 1;

            if (digit == 0) {
                width += 4;
            }
            else if (digit == 1) {
                width += 2;
            }
            else {
                width += 3;
            }
        }

        cout << width << "\n";
    }

    return 0;
}
