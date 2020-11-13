#include <iostream>
#include <string>

using namespace std;

struct Point {
    int x, y;

    Point() : x(0), y(0) {}
    Point(int x, int y) : x(x), y(y) {}

    bool outOfRange() const {
        return this->x < 1 || this->x > 8 || this->y < 1 || this->y > 8;
    }

    bool operator==(const Point& p) const {
        return this->x == p.x && this->y == p.y;
    }

    Point operator+(const Point& p) const {
        return Point(this->x + p.x, this->y + p.y);
    }
};

Point stringToPoint(const string& str)
{
    return Point(str[0] - 64, str[1] - 48);
}

string pointToString(const Point& p)
{
    string result = "";

    result.push_back(p.x + 64);
    result.push_back(p.y + 48);

    return result;
}

Point commandToPoint(const string& command)
{
    if (command == "R") return Point(1, 0);
    else if (command == "L") return Point(-1, 0);
    else if (command == "B") return Point(0, -1);
    else if (command == "T") return Point(0, 1);
    else if (command == "RT") return Point(1, 1);
    else if (command == "LT") return Point(-1, 1);
    else if (command == "RB") return Point(1, -1);
    else return Point(-1, -1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string kingString, stoneString;
    int n;
    cin >> kingString >> stoneString >> n;

    Point kingPoint = stringToPoint(kingString);
    Point stonePoint = stringToPoint(stoneString);

    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;

        Point deltaPoint = commandToPoint(command);
        Point afterKingPoint = kingPoint + deltaPoint;
        Point afterStonePoint = stonePoint + deltaPoint;

        if (afterKingPoint.outOfRange()) {
            continue;
        }

        if (afterKingPoint == stonePoint) {
            if (afterStonePoint.outOfRange()) {
                continue;
            }

            stonePoint = afterStonePoint;
        }

        kingPoint = afterKingPoint;
    }

    cout << pointToString(kingPoint) << "\n";
    cout << pointToString(stonePoint) << "\n";

    return 0;
}