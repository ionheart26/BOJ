#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a[10001];
int ind[10001];
int time[10001];
int d[10001];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d %d", &time[i], &x);
		ind[i] = x;
		while (x--) {
			int y;
			scanf("%d", &y);
			a[y].push_back(i);
		}
	}
	
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (ind[i] == 0) {
			q.push(i);
			d[i] = time[i];
		}
	}
	while (!q.empty()) {
		int t = q.front(); q.pop();
		for (int x : a[t]) {
			ind[x]--;
			if (d[x] < d[t] + time[x]) {
				d[x] = d[t] + time[x];
			}
			if (ind[x] == 0) {
				q.push(x);
			}
		}
	}

	printf("%d", *max_element(d + 1, d + n + 1));
	return 0;	
}
