#include<bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
#define ll long long
using namespace std;

bool isvalid(int d, int n, int c, vector<int> &v){
	int i = 1;
	int prev = v[0];
	int cur;
	c--;
	while(c and i<n){
		cur = v[i];
		if(cur-prev>=d)
			c--, prev = cur;
		i++;
	}
	if(c) return false;
	return true;
}

int solve(int n, int c, vector<int> &v){
	int l = 0, u = 1e9;
	int res = 0;
	while(l<=u){
		int mid = (l+u)/2;
		if(isvalid(mid, n, c, v))
			res = max(res, mid), l = mid+1;
		else u = mid-1;
	}
	return res;
}

int main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin>>t;
	while(t--){
		int n, c;
		cin>>n>>c;
		vector<int> v(n);
		for(int i=0; i<n; i++){
			cin>>v[i];
		}
		sort(v.begin(), v.end());
		cout<<solve(n, c, v)<<endl;
	}
}
