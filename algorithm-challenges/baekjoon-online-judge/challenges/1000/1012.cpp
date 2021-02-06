#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int T;
	cin >> T;

	while (T--) {
		int M, N, K;
		cin >> M >> N >> K;

		int map[50][50] = { 0 };
		int cnt = 0;

		while (K--) {
			int X, Y;
			cin >> X >> Y;
			map[Y][X] = 1;
		}

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				if (!map[y][x]) {
					continue;
				}

				queue<int> bfs;
				bfs.push(y * 100 + x);

				while (!bfs.empty()) {
					int tx = bfs.front() % 100;
					int ty = bfs.front() / 100;
					bfs.pop();
					map[ty][tx] = 0;
					
					if (tx > 0 && map[ty][tx - 1]) {
						bfs.push(ty * 100 + (tx - 1));
						map[ty][tx - 1] = 0;
					}

					if (tx < M - 1 && map[ty][tx + 1]) {
						bfs.push(ty * 100 + (tx + 1));
						map[ty][tx + 1] = 0;
					}

					if (ty > 0 && map[ty - 1][tx]) {
						bfs.push((ty - 1) * 100 + tx);
						map[ty - 1][tx] = 0;
					}

					if (ty < N - 1 && map[ty + 1][tx]) {
						bfs.push((ty + 1) * 100 + tx);
						map[ty + 1][tx] = 0;
					}
				}

				cnt++;
			}
		}

		cout << cnt << "\n";
	}

	return 0;
}