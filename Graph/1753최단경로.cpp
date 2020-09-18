#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair < int, int > ii;
const int INF = 100000000;
int main(){
	int V,E,K;
	scanf("%d %d %d",&V,&E,&K);
	vector < vector < ii > > ls(V+1);
	vector < bool > visited(V+1,0);
	vector < int > dist(V+1,INF);
	for(int i=0;i<E;i++){
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		ls[u].push_back(ii(v,w));
	}
	int now=K;
	priority_queue < ii, vector < ii >, greater < ii > > PQ;
	dist[now]=0;
	PQ.push(ii(0,now));
	while(!PQ.empty()){
		do{
			now=PQ.top().second;
			PQ.pop();
		}while(visited[now]&&!PQ.empty());
		if(visited[now]) break;
		visited[now]=1;
		for(int i=0;i<ls[now].size();i++){
			int next=ls[now][i].first, d=ls[now][i].second;
			if(!visited[next] && dist[next]>dist[now]+d){
				dist[next]=dist[now]+d;
				PQ.push(ii(dist[next],next));
			}
		}
	}
	for(int i=1;i<V+1;i++){
		if(dist[i]==INF)
			puts("INF");
		else
			printf("%d\n",dist[i]);
	}
	return 0;
}
