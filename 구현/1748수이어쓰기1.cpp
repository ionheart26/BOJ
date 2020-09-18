#include <iostream>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	long long ans = 0;
	for (int start = 1, len = 1; start <= n; start *= 10, len++) {
		int end = start * 10 - 1;
		if (end > n) {
			end = n;
		}
		ans += (end - start + 1) * len;
	}
	printf("%d", ans);
	return 0;
}
