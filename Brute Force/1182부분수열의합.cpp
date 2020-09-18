#include <cstdio>
int main() {
	int n, s;
	scanf("%d %d", &n, &s);
	int a[20];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int count = 0;
	for (int i = 1; i < (1 << n); i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) sum += a[j];
		}
		if (sum == s) count++;
	}
	printf("%d", count);
	return 0;
}
