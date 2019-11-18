#define MAX(A,B) A<B ? B : A

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	//d[i]: maximum consecutive sum with ith element in the last
	int a[100000];
	int d[100000];
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d ", a+i);
	}
	for(int i = 0; i < n; i++){
		d[i] = a[i];
		if(i == 0) continue;
		if(d[i-1] > 0){
			d[i] += d[i-1];
		}
	}
	int max = d[0];
	for(int i = 1; i < n; i++){
		max = MAX(max,d[i]);
	}
	printf("%d", max);
	return 0;
}
