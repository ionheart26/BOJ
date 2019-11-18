#include<stdio.h>
int cache[1001];
int tile(int n){
	if(n==1) return 1;
	else if(n==2) return 3;
	if(cache[n]!=-1) return cache[n]%10007;
	cache[n]=tile(n-1)+2*tile(n-2);
	return cache[n]%10007;
}
int main(){
	int n,i;
	scanf("%d",&n);
	for(i=0;i<1001;i++) cache[i]=-1;
	printf("%d\n",tile(n));
	return 0;
}
