#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	vector<pair<int,string> > v;
	int n;
	cin >> n;
	v.resize(n);
	for(int i=0;i<n;i++){
	cin >> v[i].second;
	v[i].first = v[i].second.length();
	}
	sort(v.begin(), v.end());
	cout << v[0].second << endl;
	for(int i=1;i<n;i++){
		if(v[i-1].second!=v[i].second)
		cout << v[i].second << endl;
	}
	return 0;
}
