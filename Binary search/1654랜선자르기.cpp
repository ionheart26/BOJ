#include <cstdio>
long long a[10000];
int k, n;
bool check(long long x) {
	int cnt = 0;
	for (int i = 0; i < k; i++) {
		cnt += a[i] / x;
	}
	return cnt >= n;
}
int binary_search(long long left, long long right) {
	while (left <= right) {
		long long mid = (left + right) / 2;
		if (check(mid)) {
			left = mid + 1;
		}
		else right = mid - 1;
	}
	return left-1;
}
int main() {
	scanf("%d %d", &k, &n);
	long long max = 0;
	for (int i = 0; i < k; i++) {
		scanf("%d", &a[i]);
		if (max < a[i]) max = a[i];
	}
	printf("%lld", binary_search(1, max));
	return 0;
}
