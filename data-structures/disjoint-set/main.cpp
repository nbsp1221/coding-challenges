#include "DisjointSet.h"

#include <iostream>
#include <vector>

using namespace std;

void printDisjointSet(DisjointSet disjointSet)
{
    vector<vector<int>> info(disjointSet.size());

    for (int i = 0; i < disjointSet.size(); i++) {
        info[disjointSet.find(i)].push_back(i);
    }

    for (int i = 0; i < disjointSet.size(); i++) {
        if (info[i].size() == 0) {
            continue;
        }

        cout << "{ ";

        for (size_t j = 0; j < info[i].size(); j++) {
            cout << info[i][j];
            cout << (j + 1 == info[i].size() ? "" : ", ");
        }

        cout << " } ";
    }

    cout << "\n";
}

int main()
{
    DisjointSet disjointSet(10);

    cout << "Initialize" << "\n";
    printDisjointSet(disjointSet);
    cout << "\n";

    cout << "Union 2 and 5" << "\n";
    disjointSet.merge(2, 5);
    printDisjointSet(disjointSet);
    cout << "\n";

    cout << "Union 5 and 7" << "\n";
    disjointSet.merge(5, 7);
    printDisjointSet(disjointSet);
    cout << "\n";

    cout << "Union 5 and 0" << "\n";
    disjointSet.merge(5, 0);
    printDisjointSet(disjointSet);
    cout << "\n";

    cout << "Union 4 and 8" << "\n";
    disjointSet.merge(4, 8);
    printDisjointSet(disjointSet);
    cout << "\n";

    cout << "Union 9 and 4" << "\n";
    disjointSet.merge(9, 4);
    printDisjointSet(disjointSet);
    cout << "\n";

    cout << "Union 1 and 6" << "\n";
    disjointSet.merge(1, 6);
    printDisjointSet(disjointSet);
    cout << "\n";

    cout << "Union 8 and 0" << "\n";
    disjointSet.merge(8, 0);
    printDisjointSet(disjointSet);
    cout << "\n";

    return 0;
}