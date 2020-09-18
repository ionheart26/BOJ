#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	int d[100001];
	fill_n(d, 100001, -1);

	queue<int> q;
	q.push(n);
	d[n] = 0;
	while (!q.empty()) {
		int t = q.front(); q.pop();
		int nt = t + 1;
		if (0 <= nt && nt <= 100000 && d[nt] == -1) {
			q.push(nt);
			d[nt] = d[t] + 1;
		}
		nt = t - 1;
		if (0 <= nt && nt <= 100000 && d[nt] == -1) {
			q.push(nt);
			d[nt] = d[t] + 1;
		}
		nt = t*2;
		if (0 <= nt && nt <= 100000 && d[nt] == -1) {
			q.push(nt);
			d[nt] = d[t] + 1;
		}
	}
	printf("%d", d[k]);
	return 0;
}
