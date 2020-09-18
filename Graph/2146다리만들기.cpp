#include <iostream>
#include <queue>
using namespace std;
int n;
int map[100][100];
int g[100][100];
int d[100][100];
int dr[] = { 0, 0, 1, -1 };
int dc[] = { 1, -1, 0, 0 };
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1 && g[i][j] == 0) {
				g[i][j] = ++cnt;
				queue<pair<int, int>> q;
				q.push(make_pair(i, j));
				while (!q.empty()) {
					int r = q.front().first;
					int c = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++) {
						int nr = r + dr[k];
						int nc = c + dc[k];
						if (!(0 <= nr && nr < n && 0 <= nc && nc < n)) continue;
						if (map[nr][nc] == 1 && g[nr][nc] == 0) {
							q.push(make_pair(nr, nc));
							g[nr][nc] = cnt;
						}
					}
				}
			}
		}
	}

	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1) {
				q.push(make_pair(i, j));
				d[i][j] = 0;
			}
			else d[i][j] = -1;
		}
	}
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nr = r + dr[k];
			int nc = c + dc[k];
			if (!(0 <= nr && nr < n && 0 <= nc && nc < n)) continue;
			if (g[nr][nc] == 0) {
				q.push(make_pair(nr, nc));
				g[nr][nc] = g[r][c];
				d[nr][nc] = d[r][c] + 1;
			}
		}
	}

	int ans = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (((j + 1) < n) && (g[i][j] != g[i][j + 1])) {
				if (ans == -1) ans = d[i][j] + d[i][j + 1];
				else ans = min(ans, d[i][j] + d[i][j + 1]);
			}
			if (((i + 1) < n) && (g[i][j] != g[i + 1][j])) {
				if (ans == -1) ans = d[i][j] + d[i + 1][j];
				else ans = min(ans, d[i][j] + d[i + 1][j]);
			}
		}
	}
	printf("%d", ans);
	return 0;
}
