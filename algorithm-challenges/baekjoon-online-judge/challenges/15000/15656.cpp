#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> list;

void solve(const vector<int>& results)
{
	if (results.size() == m) {
		for (int i = 0; i < m; i++) {
			cout << list[results[i]];
			cout << (i < m - 1 ? " " : "\n");
		}

		return;
	}

	for (int i = 0; i < n; i++) {
		vector<int> copyResults = results;
		copyResults.push_back(i);
		solve(copyResults);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;

	list.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> list[i];
	}

	sort(list.begin(), list.end());

	for (int i = 0; i < n; i++) {
		vector<int> results(1, i);
		solve(results);
	}

	return 0;
}