#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int arr[4];
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];

    int increasing = 0;
    int decreasing = 0;
    int identical = 0;

    for (int i = 1; i < 4; i++) {
        if (arr[i - 1] < arr[i]) increasing++;
        if (arr[i - 1] > arr[i]) decreasing++;
        if (arr[i - 1] == arr[i]) identical++;
    }

    if (identical == 3) {
        cout << "Fish At Constant Depth" << "\n";
    }
    else if (increasing == 3) {
        cout << "Fish Rising" << "\n";
    }
    else if (decreasing == 3) {
        cout << "Fish Diving" << "\n";
    }
    else {
        cout << "No Fish" << "\n";
    }
}
