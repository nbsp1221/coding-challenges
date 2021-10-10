#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    deque<int> people(n);
    deque<pair<int, int>> pathInfo;
    int elapsedTime = 0;

    for (int i = 0; i < n; i++) {
        cin >> people[i];
    }

    sort(people.begin(), people.end());

    while (!people.empty()) {
        if (people.size() == 1) {
            pathInfo.push_back(make_pair(people[0], -1));
            break;
        }

        if (people.size() == 2) {
            pathInfo.push_back(make_pair(people[0], people[1]));
            break;
        }

        if (people.size() == 3) {
            pathInfo.push_back(make_pair(people[0], people[1]));
            pathInfo.push_back(make_pair(people[0], -1));
            pathInfo.push_back(make_pair(people[0], people[2]));

            break;
        }

        int frontFirst = people[0];
        int frontSecond = people[1];
        int backFirst = people.back();
        int backSecond = *(people.end() - 2);

        if (frontFirst * 2 + backFirst + backSecond < frontSecond * 2 + frontFirst + backFirst) {
            pathInfo.push_back(make_pair(frontFirst, backFirst));
            pathInfo.push_back(make_pair(frontFirst, -1));
            pathInfo.push_back(make_pair(frontFirst, backSecond));
            pathInfo.push_back(make_pair(frontFirst, -1));
        }
        else {
            pathInfo.push_back(make_pair(frontFirst, frontSecond));
            pathInfo.push_back(make_pair(frontFirst, -1));
            pathInfo.push_back(make_pair(backSecond, backFirst));
            pathInfo.push_back(make_pair(frontSecond, -1));
        }

        people.pop_back();
        people.pop_back();
    }

    for (auto i = 0u; i < pathInfo.size(); i++) {
        elapsedTime += pathInfo[i].second == -1 ? pathInfo[i].first : pathInfo[i].second;
    }

    cout << elapsedTime << "\n";
    
    for (auto i = 0u; i < pathInfo.size(); i++) {
        if (pathInfo[i].second == -1) {
            cout << pathInfo[i].first << "\n";
        }
        else {
            cout << pathInfo[i].first << " " << pathInfo[i].second << "\n";
        }
    }

    return 0;
}
