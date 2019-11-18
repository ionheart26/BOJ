#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
using namespace std;
typedef pair<int,int> ii;
const int INF = 100*1000+1;
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
			if(!visited[next]&&dist[next]>dist[now]+d){
				dist[next]=dist[now]+d;
				PQ.push(ii(dist[next],next));
			}
		}
	}
	return dist[e];
}
int main(){
	int M,X;
	scanf("%d %d %d",&N,&M,&X);
	ls.resize(N+1);
	for(int i=0;i<M;i++){
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		ls[u].push_back(ii(v,w));
	}
	vector < int > ans(N+1);
	priority_queue < ii > PQ;
	for(int i=1;i<N+1;i++){
		ans[i]=dijk(i,X)+dijk(X,i);
		PQ.push(ii(ans[i],i));
	}
	printf("%d\n",PQ.top().first);
	return 0;
}
