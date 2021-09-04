#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        int n;
        cin >> n;

        if (n == 0) {
            break;
        }

        vector<double> students(n);
        double sum = 0;
        double average = 0;
        double firstAnswer = 0, secondAnswer = 0;

        for (int i = 0; i < n; i++) {
            cin >> students[i];
            sum += students[i];
        }

        average = sum / (double)n;
        average = round(average * 100) / 100;

        for (int i = 0; i < n; i++) {
            if (students[i] < average) {
                firstAnswer += average - students[i];
            }
            else if (students[i] > average) {
                secondAnswer += students[i] - average;
            }
        }

        cout.precision(2);
        cout << fixed;
        cout << "$" << min(firstAnswer, secondAnswer) << "\n";
    }

    return 0;
}
