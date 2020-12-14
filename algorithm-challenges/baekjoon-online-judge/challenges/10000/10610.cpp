#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;

    int digitSum = 0;
    sort(str.begin(), str.end(), greater<char>());

    for (size_t i = 0; i < str.size(); i++) {
        digitSum += str[i] - '0';
    }

    if (str.back() == '0' && digitSum % 3 == 0) {
        cout << str << "\n";
    }
    else {
        cout << -1 << "\n";
    }

    return 0;
}