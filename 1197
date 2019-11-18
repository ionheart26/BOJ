#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

long long parent[10001];
vector < pair < long long, pair <int, int> > > g;

long long Find(long long x){
	return x==parent[x]?x:parent[x]=Find(parent[x]);
}

void Union(long long x, long long y){
	parent[Find(x)]=Find(y);
}

int main(){
	//freopen("in.txt" ,"r", stdin);
	long long v,e, a,b,cost, U,V, ans=0;
	scanf("%lld %lld",&v,&e);
	for(int i=0; i<e; i++){
		scanf("%lld %lld %lld",&a,&b,&cost);
		g.push_back(make_pair(cost,make_pair(a,b)));
	}

	for(int i=1; i<=v; i++) parent[i] = i;
	sort(g.begin(),g.end());

	for(int i=0; i<e; i++){
		U=g[i].second.first, V=g[i].second.second;
		if(Find(U)==Find(V)) continue;
		Union(U,V);
		ans += g[i].first;
	}
	printf("%d",ans);
    return 0;
}
