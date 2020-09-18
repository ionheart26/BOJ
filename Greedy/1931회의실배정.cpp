#include <iostream>
#include <vector>
#include <algorithm>
#define pair pair<int,int>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<pair> v(n);//end, start
    for(int i = 0; i < n; i++){
        scanf("%d %d", &v[i].second, &v[i].first);
    }
    sort(v.begin(), v.end());
    int ans = 0;
    int time = 0;
    for(int i = 0; i < n; i++){
        if(i != 0 && time > v[i].second) continue;
        ans++;
        time = v[i].first;
    }
    printf("%d", ans);
    return 0;
}
