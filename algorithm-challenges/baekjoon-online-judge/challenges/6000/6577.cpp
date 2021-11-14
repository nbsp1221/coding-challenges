#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Node {
public:
    string destinationCity;
    int departureTime;
    int durationTime;

public:
    Node(string destinationCity, int departureTime, int durationTime) {
        this->destinationCity = destinationCity;
        this->departureTime = departureTime;
        this->durationTime = durationTime;
    }
};

class QueueInfo {
public:
    string currentCity;
    int currentTime;
    int bloodCount;

public:
    QueueInfo(string currentCity, int currentTime, int bloodCount) {
        this->currentCity = currentCity;
        this->currentTime = currentTime;
        this->bloodCount = bloodCount;
    }
};

int addTime(int t1, int t2)
{
    return (t1 + t2) % 24;
}

bool isPossibleTravel(int currentTime, int departureTime)
{
    currentTime = currentTime <= 6 ? currentTime + 24 : currentTime;
    departureTime = departureTime <= 6 ? departureTime + 24 : departureTime;

    return currentTime <= departureTime;
}

void testCase()
{
    int n;
    cin >> n;

    unordered_map<string, vector<Node>> graph;

    for (int i = 0; i < n; i++) {
        string departureCity, destinationCity;
        int departureTime, durationTime;
        cin >> departureCity >> destinationCity >> departureTime >> durationTime;

        departureTime %= 24;

        if (departureTime >= 6 && departureTime < 18) continue;
        if (durationTime > 12) continue;
        if (addTime(departureTime, durationTime) > 6 && addTime(departureTime, durationTime) < 18) continue;

        if (graph.count(departureCity)) {
            graph[departureCity].push_back(Node(destinationCity, departureTime, durationTime));
        }
        else {
            graph[departureCity] = vector<Node>(1, Node(destinationCity, departureTime, durationTime));
        }
    }

    string finalDepartureCity, finalDestinationCity;
    cin >> finalDepartureCity >> finalDestinationCity;

    queue<QueueInfo> bfsQueue;
    unordered_map<string, int> table;

    bfsQueue.push(QueueInfo(finalDepartureCity, 18, 0));
    table[finalDepartureCity] = 0;

    while (!bfsQueue.empty()) {
        QueueInfo queueInfo = bfsQueue.front();
        bfsQueue.pop();

        string currentCity = queueInfo.currentCity;
        int currentTime = queueInfo.currentTime;
        int bloodCount = queueInfo.bloodCount;

        if (table.count(currentCity) && bloodCount > table[currentCity]) {
            continue;
        }

        for (uint i = 0; i < graph[currentCity].size(); i++) {
            string destinationCity = graph[currentCity][i].destinationCity;
            int departureTime = graph[currentCity][i].departureTime;
            int durationTime = graph[currentCity][i].durationTime;
            int nextBloodCount = bloodCount + (int)(!isPossibleTravel(currentTime, departureTime));

            if (table.count(destinationCity) && table[destinationCity] <= nextBloodCount) {
                continue;
            }

            table[destinationCity] = nextBloodCount;
            bfsQueue.push(QueueInfo(destinationCity, addTime(departureTime, durationTime), nextBloodCount));
        }
    }

    if (table.count(finalDestinationCity)) {
        cout << "Vladimir needs " << table[finalDestinationCity] << " litre(s) of blood." << "\n";
    }
    else {
        cout << "There is no route Vladimir can take." << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cout << "Test Case " << (i + 1) << "." << "\n";
        testCase();
    }

    return 0;
}
