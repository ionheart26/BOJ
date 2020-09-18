#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
using namespace std;
typedef pair < int, int > ii;
const int INF = 100000*999;
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	vector < vector < ii > > ls(n+1);
	vector < bool > visited(n+1,0);
	vector < int > dist(n+1,INF);
	for(int i=0;i<m;i++){
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		ls[u].push_back(ii(v,w));
	}
	int s,e;
	scanf("%d %d",&s,&e);
	//dijkstra
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
	//end
	printf("%d\n",dist[e]);
	return 0;
}
