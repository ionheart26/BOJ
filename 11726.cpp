#include <stdio.h>
int compute(int n);
int memo[1001];
int main(void) {
	int n, i;
	//initialization
	memo[1] = 1;
	memo[2] = 2;
	scanf("%d", &n);
	printf("%d", compute(n));
	return 0;
}
int compute(int n) {
	//base condition is set in the main function
	//which is
	//	memo[1] = 1;
	//	memo[2] = 2;
	if (memo[n] != 0) {
		return memo[n];
	}
	else {
		memo[n] = compute(n-1) + compute(n-2);
        memo[n] %= 10007;
		return memo[n];
	}
}

