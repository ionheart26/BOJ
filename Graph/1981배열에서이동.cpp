#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
using namespace std;

int dr[] = { 0, 0, 1, -1 };
int dc[] = { 1, -1, 0, 0 };
int n;
int a[101][101];
bool check(int diff) {
	for (int min = 0; min + diff <= 200; min++) {
		if (!(min <= a[1][1] && a[1][1] <= min + diff)) continue;
		queue<pair<int, int>> q;
		q.push({ 1, 1 });
		bool visited[101][101];
		fill(visited[0], visited[101], false);
		visited[1][1] = true;
		while (!q.empty()) {
			int r, c;
			tie(r, c) = q.front(); q.pop();
			for (int i = 0; i < 4; i++) {
				int nr = r + dr[i];
				int nc = c + dc[i];
				if (!(1 <= nr && nr <= n && 1 <= nc && nc <= n))continue;
				if (!visited[nr][nc]) {
					if (min <= a[nr][nc] && a[nr][nc] <= min + diff) {
						q.push({ nr, nc });
						visited[nr][nc] = true;
					}
				}
			}
		}
		if (visited[n][n])return true;
	}
	return false;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	int l = 0;
	int r = 200;
	int ans;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			r = mid - 1;
			ans = mid;
		}
		else {
			l = mid + 1;
		}
	}
	printf("%d", ans);
	return 0;
}
