#include <iostream>
#include <queue>
using namespace std;
bool visited[101][101];
int a[101][101];
int d[101][101];
int dr[] = { 0, 0, 1, -1 };
int dc[] = { 1, -1, 0, 0 };
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &a[i][j]);
		}
	}
	queue<pair<int, int>> q;
	q.push({ 1, 1 });
	d[1][1] = 1;
	visited[1][1] = true;
	while (!q.empty()) {
		int r = q.front().first; 
		int c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (!(0 < nr && nr <= n && 0 < nc && nc <= m)) continue;
			if (a[nr][nc] && !visited[nr][nc]) {
				q.push({ nr, nc });
				visited[nr][nc] = true;
				d[nr][nc] = d[r][c] + 1;
			}
		}
	}
	printf("%d", d[n][m]);
	return 0;
}
