#include<bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
#define ll long long
using namespace std;

bool isvalid(int n, string s){
	vector<int> v(4);
	for(int i=0; i<n-1; i++){
		int idx = s[i]-'0';
		v[idx]++;
	}
	for(int i=n-1; i<s.size(); i++){
		int idx = s[i]-'0';
		v[idx]++;
		if(v[1]>0 and v[2]>0 and v[3]>0) return true;
		idx = s[i-n+1]-'0';
		v[idx]--;
	}
	return false;
}

int bs(string s){
	int l = 3, u = s.size();
	int res = INT_MAX;
	while(l<=u){
		int mid = (l+u)/2;
		if(isvalid(mid, s))
			res = min(res, mid), u = mid-1;
		else l = mid+1;
	}
	if(res==INT_MAX) return 0;
	return res;
}

int main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		cout<<bs(s)<<endl;
	}
}
