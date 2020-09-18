#include <iostream>
#include <string>
#include <queue>
#include <map>
using namespace std;
int dr[] = { 0,0,1,-1 };
int dc[] = { 1,-1,0,0 };
int main() {
	int start = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int temp;
			scanf("%d", &temp);
			if (temp == 0) temp = 9;
			start = start * 10 + temp;
		}
	}

	queue<int> q;
	q.push(start);
	map<int, int> d;
	d[start] = 0;
	while (!q.empty()) {
		int tn = q.front(); q.pop();
		string tstr = to_string(tn);
		int nine_index = tstr.find('9');
		int nine_r = nine_index / 3;
		int nine_c = nine_index % 3;
		for (int i = 0; i < 4; i++) {
			int next_r = nine_r + dr[i];
			int next_c = nine_c + dc[i];
			if (!(0 <= next_r && next_r < 3 && 0 <= next_c && next_c < 3)) continue;
			string nstr = tstr;
			swap(nstr[nine_index], nstr[next_r * 3 + next_c]);
			int nn = stoi(nstr);
			if (d.count(nn) == 0) {
				q.push(nn);
				d[nn] = d[tn] + 1;
			}
		}
	}

	int end = 123456789;
	int ans = -1;
	if (d.count(end) != 0) ans = d[end];
	printf("%d", ans);
	return 0;
}
