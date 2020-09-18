#include <iostream>
#include <queue>
using namespace std;
struct Edge {
	int a, b, cost;
	Edge(int a, int b, int cost) : a(a), b(b), cost(cost) {
	}
	bool operator > (const Edge &other) const{
		return cost > other.cost;
	}
};
int parent[10001];
int Find(int a) {
	if (parent[a] == a) return a;
	return parent[a] = Find(parent[a]);
}
void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	parent[b] = a;
}
int main() {
	int v, e;
	scanf("%d %d", &v, &e);
	for (int i = 1; i <= v; i++) {
		parent[i] = i;
	}
	priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		Edge edge = Edge(a, b, c);
		pq.push(edge);
	}
	int ans = 0;
	while (!pq.empty()) {
		Edge edge = pq.top(); pq.pop();
		if (Find(edge.a) == Find(edge.b)) continue;
		Union(edge.a, edge.b);
		ans += edge.cost;
	}
	printf("%d", ans);
	return 0;
}
