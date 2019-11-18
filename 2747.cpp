#include<stdio.h>
int cache[46]={-1};
int Fibo(int n){
	if(n==0||n==1) return n;
	if(cache[n]!=-1) return cache[n];
	cache[n]=Fibo(n-2)+Fibo(n-1);
	return cache[n];
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<46;i++)
		cache[i]=-1;
	printf("%d\n",Fibo(n));
	return 0;
}
