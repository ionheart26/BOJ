#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n;
vector<pair<int, int>> map[1001];
bool visited[1001];
int main() {
	scanf("%d", &n);
	int e;
	scanf("%d", &e);
	for (int i = 0; i < e; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		map[a].push_back(make_pair(b, c));
		map[b].push_back(make_pair(a, c));
	}

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	visited[1] = true;
	for (auto &p : map[1]) {
		pq.push(make_pair(p.second, p.first));
	}
	int ans = 0;
	while (!pq.empty()) {
		auto t = pq.top(); pq.pop();
		int n = t.second;
		if (visited[n]) continue;
		ans += t.first;
		visited[n] = true;
		for (auto& p : map[n]) {
			if (visited[p.first]) continue;
			pq.push(make_pair(p.second, p.first));
		}
	}

	printf("%d", ans);
	return 0;
}
