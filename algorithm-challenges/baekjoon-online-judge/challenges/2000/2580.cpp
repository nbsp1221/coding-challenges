#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x, y;

    Point() : x(0), y(0) {}
    Point(int x, int y) : x(x), y(y) {}
};

int gameBoard[9][9];
vector<pair<Point, int>> emptyPoints;
bool horizontalStates[9][9] = { 0, };
bool verticalStates[9][9] = { 0, };
bool rectangleStates[3][3][9] = { 0, };
bool isSolved = false;

void setNumber(int x, int y, int number, bool state)
{
    horizontalStates[y][number - 1] = state;
    verticalStates[x][number - 1] = state;
    rectangleStates[y / 3][x / 3][number - 1] = state;
}

void findSolution(int index)
{
    if (isSolved) {
        return;
    }

    if (index + 1 == static_cast<int>(emptyPoints.size())) {
        for (auto emptyPoint : emptyPoints) {
            gameBoard[emptyPoint.first.y][emptyPoint.first.x] = emptyPoint.second;
        }

        isSolved = true;
        return;
    }

    int x = emptyPoints[index + 1].first.x;
    int y = emptyPoints[index + 1].first.y;

    for (int i = 1; i <= 9; i++) {
        if (horizontalStates[y][i - 1] || verticalStates[x][i - 1] || rectangleStates[y / 3][x / 3][i - 1]) {
            continue;
        }

        emptyPoints[index + 1].second = i;
        setNumber(x, y, i, true);
        findSolution(index + 1);
        setNumber(x, y, i, false);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 9; x++) {
            cin >> gameBoard[y][x];

            if (gameBoard[y][x] == 0) {
                emptyPoints.push_back(make_pair(Point(x, y), 0));
            }
            else {
                setNumber(x, y, gameBoard[y][x], true);
            }
        }
    }

    findSolution(-1);

    for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 9; x++) {
            cout << gameBoard[y][x] << " ";
        }

        cout << "\n";
    }

    return 0;
}