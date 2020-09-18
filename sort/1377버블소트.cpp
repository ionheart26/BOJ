#include <iostream>
#include <algorithm>
using namespace std;
pair<int, int> a[500001];//(value, index)
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i].first);
		a[i].second = i;
	}
	
	sort(a + 1, a + n + 1);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (ans < a[i].second - i) {
			ans = a[i].second - i;
		}
	}
	printf("%d", ans + 1);
	return 0;
}
