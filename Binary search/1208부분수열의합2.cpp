#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int a[40];
int subsum_index;
int first[1 << 20];
int second[1 << 20];
void get_subsum(int index, int e, int sum, int subsum[]) {
	if (index > e) {
		subsum[subsum_index++] = sum;
		return;
	}
	get_subsum(index + 1, e, sum, subsum);
	get_subsum(index + 1, e, sum + a[index], subsum);
}
int main() {
	int n, s;
	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	get_subsum(0, (n-1) / 2, 0, first);
	subsum_index = 0;
	get_subsum(((n-1) / 2) + 1, n - 1, 0, second);
	int m = n / 2;
	n = n - m;
	n = (1 << n);
	m = (1 << m);
	sort(first, first + n);
	sort(second, second + m);
	reverse(second, second + m);
	int i = 0, j = 0;
	long long count = 0;
	while (i < n && j < m) {
		int sum = first[i] + second[j];
		if (sum < s) i++;
		else if (sum > s) j++;
		else {
			long long ub1 = i;
			while (ub1 < n && first[ub1] == first[i]) {
				ub1++;
			}
			long long ub2 = j;
			while (ub2 < m && second[ub2] == second[j]) {
				ub2++;
			}
			count += (ub1 - i) * (ub2 - j);
			i = ub1;
			j = ub2;
		}
	}
	if (s == 0) count--;
	printf("%lld", count);
	return 0;
}
