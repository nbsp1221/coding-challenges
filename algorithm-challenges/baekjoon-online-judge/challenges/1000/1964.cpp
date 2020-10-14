#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int nowTerm = 5;
    int difference = 7;

    for (int i = 1; i < n; i++) {
        nowTerm = (nowTerm + difference) % 45678;
        difference += 3;
    }

    cout << nowTerm << "\n";
    return 0;
}