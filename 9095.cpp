#include <stdio.h>
int memo[11];
int main(void) {
	int T, n;
	//initialization
	for (int i = 1; i <= 3; i++) {
		for (int j = 0; j < i; j++) {
			memo[i] += memo[j];
		}
		memo[i]++;
	}
	for (int i = 4; i <= 12; i++) {
		memo[i] = memo[i - 1] + memo[i - 2] + memo[i - 3];
	}
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		printf("%d\n", memo[n]);
	}
	return 0;
}
