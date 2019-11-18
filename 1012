#include <cstdio>
#include <queue>
using namespace std;

bool field[50][50]={0};
bool visited[50][50]={0};

int bfs(int i, int j){
	queue < pair < int, int > > q;
	q.push(make_pair(i,j));
	while(!q.empty()){
		int ni=q.front().first;
		int nj=q.front().second;

		if(nj+1!=50){
			if(visited[ni][nj+1]==0&&field[ni][nj+1]==1){
				q.push(make_pair(ni,nj+1));
				visited[ni][nj+1]=1;
			}
		}
		if(ni-1!=-1){
			if(visited[ni-1][nj]==0&&field[ni-1][nj]==1){
				q.push(make_pair(ni-1,nj));
				visited[ni-1][nj]=1;
			}
		}
		if(ni+1!=50){
			if(visited[ni+1][nj]==0&&field[ni+1][nj]==1){
				q.push(make_pair(ni+1,nj));
				visited[ni+1][nj]=1;
			}
		}
		if(nj-1!=-1){
			if(visited[ni][nj-1]==0&&field[ni][nj-1]==1){
				q.push(make_pair(ni,nj-1));
				visited[ni][nj-1]=1;
			}
		}
		q.pop();
	}
	return 0;
}

int test(){
	int m,n,k;
	scanf("%d%d%d",&m,&n,&k);
	for(int i=0; i<50; i++)
		for(int j=0; j<50; j++)
			field[i][j]=visited[i][j]=false;
	for(int i=0;i<k;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		field[a][b]=1;
	}
	int sum=0;
	for(int i=0;i<50;i++){
		for(int j=0;j<50;j++){
			if(field[i][j]==1&&visited[i][j]==0){
				bfs(i,j);
				sum++;
			}
		}
	}
	return sum;
}

int main(){
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++) printf("%d\n",test());
	return 0;
}
