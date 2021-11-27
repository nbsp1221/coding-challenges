#include <iostream>
#include <vector>

using namespace std;

vector<int> inOrder;
vector<int> postOrder;

void preOrderTraversal(int is, int ie, int ps, int pe)
{
    int rootIndex = 0;
    int rootValue = postOrder[pe];

    if (is > ie) {
        return;
    }

    cout << rootValue << " ";

    for (int i = is; i <= ie; i++) {
        if (inOrder[i] == rootValue) {
            rootIndex = i;
            break;
        }
    }

    if (rootIndex > is) {
        preOrderTraversal(is, rootIndex - 1, ps, ps + rootIndex - is - 1);
    }

    if (rootIndex < ie) {
        preOrderTraversal(rootIndex + 1, ie, ps + rootIndex - is, pe - 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    inOrder.resize(n);
    postOrder.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> inOrder[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> postOrder[i];
    }

    preOrderTraversal(0, n - 1, 0, n - 1);
    return 0;
}
