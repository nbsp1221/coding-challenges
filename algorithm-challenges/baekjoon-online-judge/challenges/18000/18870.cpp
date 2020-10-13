#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

size_t binarySearch(const vector<int>& sorted, int target)
{
    size_t left = 0;
    size_t right = sorted.size();

    while (left <= right) {
        size_t mid = (left + right) / 2;

        if (sorted[mid] > target) {
            right = mid - 1;
        }
        else if (sorted[mid] < target) {
            left = mid + 1;
        }
        else {
            return mid;
        }
    }

    throw "Can't find the target.";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> locations(n);
    vector<int> sorted(n);

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;

        locations[i] = value;
        sorted[i] = value;
    }

    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

    for (int i = 0; i < n; i++) {
        cout << binarySearch(sorted, locations[i]) << " ";
    }

    cout << "\n";
    return 0;
}