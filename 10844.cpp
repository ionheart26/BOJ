#include <stdio.h>
#define mod 1000000000
//memoization d[s][n]
//s: start number, n: length
int d[10][101];

int main(void) {
	int n;
	scanf("%d", &n);

	//initialization
	for (int i = 0; i <= 9; i++) {
		d[i][1] = 1;
	}

	for (int i = 2; i <= n; i++) {
		d[0][i] = d[1][i-1];
		d[9][i] = d[8][i-1];
		for (int j = 1; j <= 8; j++) {
			d[j][i] = d[j - 1][i - 1] + d[j + 1][i - 1];
			d[j][i] %= mod;
		}
	}

	long long ans = 0;
	for (int i = 1; i <= 9; i++) {
		ans += d[i][n];
	}
	ans %= mod;
	printf("%d", ans);
	return 0;
}
