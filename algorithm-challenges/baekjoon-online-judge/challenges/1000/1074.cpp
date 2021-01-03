#include <iostream>

using namespace std;

int findOrder(int x, int y, int length, int startNumber)
{
    if (length == 2) {
        if (x == 0 && y == 0) {
            return startNumber;
        }
        else if (x == 1 && y == 0) {
            return startNumber + 1;
        }
        else if (x == 0 && y == 1) {
            return startNumber + 2;
        }
        else {
            return startNumber + 3;
        }
    }

    int halfLength = length / 2;
    int delta = halfLength * halfLength;

    if (x < halfLength && y < halfLength) {
        return findOrder(x, y, halfLength, startNumber);
    }
    else if (x >= halfLength && y < halfLength) {
        return findOrder(x - halfLength, y, halfLength, startNumber + delta);
    }
    else if (x < halfLength && y >= halfLength) {
        return findOrder(x, y - halfLength, halfLength, startNumber + delta * 2);
    }
    else {
        return findOrder(x - halfLength, y - halfLength, halfLength, startNumber + delta * 3);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, r, c;
    cin >> n >> r >> c;
    cout << findOrder(c, r, 1 << n, 0) << "\n";

    return 0;
}
