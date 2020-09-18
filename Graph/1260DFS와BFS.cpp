#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a[1001];
bool visited[1001];
int main() {
	int n, m, start;
	scanf("%d %d %d", &n, &m, &start);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		sort(a[i].begin(), a[i].end(), greater<int>());
	}

	stack<int> s;
	s.push(start);
	while (!s.empty()) {
		int t = s.top(); 
		s.pop();
		if (visited[t]) continue;
		visited[t] = true;
		printf("%d ", t);
		for (int n : a[t]) {
			s.push(n);
		}
	}

	for (int i = 1; i <= n; i++) {
		sort(a[i].begin(), a[i].end());
	}
	printf("\n");
	fill(visited + 1, visited + (n + 1), false);
	queue<int> q;
	q.push(start);
	visited[start] = true;
	while (!q.empty()) {
		int t = q.front(); q.pop();
		printf("%d ", t);
		for (int n: a[t]) {
			if (visited[n]) continue;
			q.push(n);
			visited[n] = true;
		}
	}
	return 0;
}
