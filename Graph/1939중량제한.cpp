#include <cstdio>
#include <vector>
//#include <utility>
#include <cstring>
using namespace std;
vector<pair<int, int>> bridge[10001];
bool visited[10001] = { false };
int st, ed;
bool check(int x, int cur) {
	if (cur == ed) return true;
	for (auto& p : bridge[cur]) {
		int next = p.first;
		int cost = p.second;
		if (!visited[next]) {
			if (cost >= x) {
				visited[next] = true;
				if (check(x, next)) return true;
			}
		}
	}
	return false;
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	while (m--) {
		int s, e, w;
		scanf("%d %d %d", &s, &e, &w);
		bridge[s].push_back(make_pair(e, w));
		bridge[e].push_back(make_pair(s, w));
	}
	scanf("%d %d", &st, &ed);
	int left = 1, right = 1000000000;
	while (left <= right) {
		int mid = (left + right) / 2;
		memset(visited, false, sizeof(visited));
		if (check(mid, st)) left = mid + 1;
		else right = mid - 1;
	}
	printf("%d", left - 1);
	return 0;
}
