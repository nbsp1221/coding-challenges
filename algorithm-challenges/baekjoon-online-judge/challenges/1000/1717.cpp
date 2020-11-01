#include <iostream>
#include <vector>

using namespace std;

class DisjointSet {
private:
    vector<int> disjointSet;

public:
    DisjointSet(int size) {
        this->disjointSet.assign(size, -1);
    }

    int find(int x) {
        if (this->disjointSet[x] < 0) {
            return x;
        }

        this->disjointSet[x] = this->find(this->disjointSet[x]);
        return this->disjointSet[x];
    }

    void merge(int x, int y) {
        x = this->find(x);
        y = this->find(y);

        if (x == y) {
            return;
        }

        if (this->disjointSet[x] > this->disjointSet[y]) {
            this->disjointSet[y] += this->disjointSet[x];
            this->disjointSet[x] = y;
        }
        else {
            this->disjointSet[x] += this->disjointSet[y];
            this->disjointSet[y] = x;
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    DisjointSet disjointSet(n + 1);

    while (m--) {
        int op, x, y;
        cin >> op >> x >> y;

        if (op == 0) {
            disjointSet.merge(x, y);
        }
        else {
            cout << (disjointSet.find(x) == disjointSet.find(y) ? "YES" : "NO") << "\n";
        }
    }

    return 0;
}