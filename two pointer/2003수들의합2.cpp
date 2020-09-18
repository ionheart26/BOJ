#include <cstdio>
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int a[10000];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int i = 0, j = 0;
	int sum = a[0];
	int count = 0;
	while (i<n && j<n) {
		if (sum > m) sum -= a[i++];
		else if (sum < m) sum += a[++j];
		else{
			count++;
			sum -= a[i++];
			sum += a[++j];
		}
	}
	printf("%d", count);
	return 0;
}
