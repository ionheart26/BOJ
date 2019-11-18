#include <stdio.h>
#define max(a,b) (a>b) ? a : b
int p[1001];
int memo[1001];
int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j<=i; j++) {
			memo[i] = max(memo[i], p[j] + memo[i - j]);
		}
	}
	printf("%d", memo[n]);
	return 0;
}
