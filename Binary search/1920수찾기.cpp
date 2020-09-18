#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main() {
	int n;
	scanf("%d", &n);
	set<int> s;
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		s.insert(t);
	}

	int m;
	scanf("%d", &m);
	vector<int> v(m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &v[i]);
		printf("%d\n", s.count(v[i]));
	}
	return 0;
}
