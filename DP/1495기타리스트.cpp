#include <cstdio>
#include <vector>
using namespace std;
int main() {
	int n, s, m;
	scanf("%d %d %d", &n, &s, &m);
	int delta[101];
	for (int i = 1; i <= n; i++) {
		scanf("%d", &delta[i]);
	}
	bool check[101][1001] = { 0 };
	check[0][s] = true;
	for (int i = 0; i <= n - 1; i++) {
		for (int j = 0; j <= m; j++) {
			if (check[i][j] == true) {
				int next = j - delta[i + 1];
				if (next >= 0) check[i + 1][next] = 1;
				next = j + delta[i + 1];
				if (next <= m) check[i + 1][next] = 1;
			}
		}
	}
	int max = -1;
	for (int i = m; i >= 0; i--) {
		if (check[n][i] == 1) {
			max = i;
			break;
		}
	}
	printf("%d", max);
	return 0;
}
