#include <stdio.h>
#define min(a,b) (a<b) ? a : b
int compute(int n);
int least[1000001];
int main(void) {
	int n;
	scanf("%d", &n);
	compute(n);
	printf("%d", least[n]);
	return 0;
}
int compute(int n) {
	if (n == 1) {
		return 0;
	}
	if (least[n] != 0) {
		return least[n];
	}
	else {
		least[n] = compute(n - 1) + 1;
		if (n % 3 == 0) {
			least[n] = min(least[n], compute(n / 3) + 1);
		}
		if (n % 2 == 0) {
			least[n] = min(least[n], compute(n / 2) + 1);
		}
		return least[n];
	}
}
