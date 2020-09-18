#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int,int> ii;
const int INF = 1000*799+1;
int N;
vector < vector < ii > > ls;
int dijk(int s, int e){
	vector < bool > visited(N+1,0);
	vector < int > dist(N+1,INF);
	dist[s]=0;
	priority_queue < ii, vector < ii >, greater < ii > > PQ;
	PQ.push(ii(0,s));
	while(!PQ.empty()){
		int now;
		do{
			now=PQ.top().second;
			PQ.pop();
		}while(visited[now]&&!PQ.empty());
		if(visited[now]||now==e) break;
		visited[now]=1;
		for(int i=0;i<ls[now].size();i++){
			int next=ls[now][i].first, d=ls[now][i].second;
			if(!visited[next] && dist[next] > dist[now]+d){
				dist[next]=dist[now]+d;
				PQ.push(ii(dist[next],next));
			}
		}
	}
	if(dist[e]==INF) return -1000*800*3-1;
	else return dist[e];
}

int main(){
	int E;
	scanf("%d %d",&N,&E);
	ls.resize(N+1);
	for(int i=0;i<E;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		ls[a].push_back(ii(b,c));
		ls[b].push_back(ii(a,c));
	}
	int A,B;
	scanf("%d %d",&A,&B);
	int dist_1_A=dijk(1,A);
	int dist_1_B=dijk(1,B);
	int dist_A_B=dijk(A,B);
	int dist_A_N=dijk(A,N);
	int dist_B_N=dijk(B,N);
	
	int ans = dist_A_B+min(dist_1_A+dist_B_N, dist_1_B+dist_A_N);
	if(ans<0) puts("-1");
	else printf("%d\n",ans);
	return 0;
}
