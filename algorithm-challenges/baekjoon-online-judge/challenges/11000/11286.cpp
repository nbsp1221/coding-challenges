#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

struct myOrder
{
    bool operator() (int left, int right) const
    {
        return abs(left) == abs(right) ? left > right : abs(left) > abs(right);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int, vector<int>, myOrder> pq;
    int n;
    cin >> n;

    while (n--) {
        int x;
        cin >> x;

        if (x == 0) {
            if (pq.empty()) {
                cout << 0 << "\n";
            }
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else {
            pq.push(x);
        }
    }

    return 0;
}