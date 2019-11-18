#include <cstdio>
#include <queue>
#include <functional>
#include <utility>
using namespace std;
typedef pair<int,int> ii;
int main(){
	int n;
	scanf("%d",&n);
	priority_queue <ii, vector<ii>, greater<ii> > con;
	for(int i=0;i<n;i++){
		int s,e;
		scanf("%d %d",&s,&e);
		con.push(ii(e,s));
	}
	int ans=0;
	while(!con.empty()){
		int now=con.top().first;
		con.pop();
		ans++;
		while(con.top().second<now && !con.empty())
			con.pop();
	}
	printf("%d\n",ans);
	return 0;
}
