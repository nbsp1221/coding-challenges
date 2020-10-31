#include <vector>

class DisjointSet {
private:
    std::vector<int> info;

public:
    DisjointSet(int size);
    int size() const;
    int find(int x);
    void merge(int x, int y);
};

DisjointSet::DisjointSet(int size)
{
    this->info.assign(size, -1);
}

int DisjointSet::size() const
{
    return this->info.size();
}

int DisjointSet::find(int x)
{
    if (this->info[x] < 0) {
        return x;
    }

    this->info[x] = this->find(this->info[x]);
    return this->info[x];
}

void DisjointSet::merge(int x, int y)
{
    x = this->find(x);
    y = this->find(y);

    if (x == y) {
        return;
    }

    if (this->info[x] > this->info[y]) {
        this->info[y] += this->info[x];
        this->info[x] = y;
    }
    else {
        this->info[x] += this->info[y];
        this->info[y] = x;
    }
}