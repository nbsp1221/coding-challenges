#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Task {
public:
    int number;
    int day;
    int fine;

public:
    Task(int number, int day, int fine) : number(number), day(day), fine(fine) {}
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<Task> tasks;

    for (int i = 0; i < n; i++) {
        int day, fine;
        cin >> day >> fine;

        tasks.push_back(Task(i + 1, day, fine));
    }

    sort(tasks.begin(), tasks.end(), [&](Task left, Task right) -> bool {
        int leftResult = left.day * right.fine;
        int rightResult = right.day * left.fine;

        return leftResult == rightResult ? left.number < right.number : leftResult < rightResult;
    });

    for (int i = 0; i < n; i++) {
        cout << tasks[i].number << " ";
    }

    cout << "\n";
    return 0;
}
