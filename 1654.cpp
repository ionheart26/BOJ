#include <stdio.h>
#include <algorithm>
using namespace std;
long long arr[10000];

int main(){
	long long k,n;
	scanf("%lld %lld",&k,&n);
	for(int i=0;i<k;i++)
		scanf("%lld",&arr[i]);
	sort(arr,arr+k);
	long long le=1,ri=arr[k-1],mid,ans=-1;
	while(le<=ri){
		long long cnt=0;
		mid=(le+ri)/2;
		for(int i=0;i<k;i++)
			cnt+=arr[i]/mid;
		if(cnt>=n){
			if(ans < mid) ans=mid;
			le=mid+1;
		}
		else if(cnt<n)
			ri=mid-1;
		//else
		//	break;
	//	ans=mid;
	}
	printf("%lld\n",ans);
	return 0;
}
