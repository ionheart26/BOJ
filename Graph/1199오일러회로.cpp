#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
void getEulerCircuit(int here, vector<int>& circuit) {
	for (int there = 0; there < adj.size(); ++there) {
		while (adj[here][there] > 0) {
			adj[here][there]--;
			adj[there][here]--;
			getEulerCircuit(there, circuit);
		}
	}
	circuit.push_back(here + 1);
}
int main() {
	int n; 
	scanf("%d", &n);
	adj.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			scanf("%d", &adj[i][j]);
			sum += adj[i][j];
		}
		if (sum % 2) {
			printf("-1");
			return 0;
		}
	}
	
	vector<int> circuit;
	getEulerCircuit(0, circuit);
	for (int x : circuit) {
		printf("%d ", x);
	}
	return 0;
}
