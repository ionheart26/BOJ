#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	long long len = 0;
	for (int start = 1, digit = 1; start <= n; start *= 10, digit++) {
		int end = start * 10 - 1;
		if (end > n) {
			end = n;
		}
		len += (end - start + 1) * digit;
	}
	if (len < k) {
		printf("-1");
		return 0;
	}
	int l = 1;
	int r = n;
	int ans = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		long long len = 0;
		int digit = 1;
		for (int start = 1; start <= mid; start *= 10, digit++) {
			int end = start * 10 - 1;
			if (end > mid) {
				end = mid;
			}
			len += (end - start + 1) * digit;
		}
		if (len == k) {
			ans = mid % 10;
			break;
		}
		else if (len > k) {
			if (len - k < digit) {
				int t = pow(10, len - k);
				ans = (mid / t) % 10;
				break;
			}
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	printf("%d", ans);
	return 0;
}
