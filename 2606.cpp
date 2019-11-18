#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

vector < vector < int > > v;

int bfs(int start,int n) {
	int sum=0;
	queue < int > q;
	vector < bool > check(n + 1,0);
	q.push(start);
	check[start] = 1;
	while (!q.empty()) {
		int now=q.front();
		for (int i = 0; i < v[now].size(); i++) {
			if (check[v[now][i]] == 0) {
				q.push(v[now][i]);
				check[v[now][i]] = 1;
				sum++;
			}
		}
		q.pop();
	}
	return sum;
}

int main() {
	int n, e;
	scanf("%d%d",&n, &e);
	v.resize(n + 1);
	for (int i = 0; i < e; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	printf("%d\n", bfs(1,n));
	return 0;
}
