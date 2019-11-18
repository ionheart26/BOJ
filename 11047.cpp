#include <cstdio>
#include <cstdlib>
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	int *coin=(int *)malloc(n*sizeof(int));
	for(int i=n-1;i>=0;i--)
		scanf("%d",coin+i);
	int ans=0;
	for(int i=0;i<n;i++){	
		if(k>=*(coin+i)){
			ans+=k/(*(coin+i));
			k=k%*(coin+i);
		}
	}
	printf("%d\n",ans);
	return 0;
}
