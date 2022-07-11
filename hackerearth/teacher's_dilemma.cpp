#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define mod 1000000007
#define int long long
 
int find(int u, int* parent){
	if(parent[u]<0)
		return u;
	return parent[u] = find(parent[u], parent);
}

void union_(int u, int v, int* parent){
	int a = find(u, parent);
	int b = find(v, parent);
	if(a!=b){
		parent[a] += parent[b];
		parent[b] = a;
	}
}

void solve(){
	int n, e; cin>>n>>e;
	int parent[n+1];
	memset(parent, -1, sizeof parent);
	while(e--){
		int u, v; cin>>u>>v;
		union_(u, v, parent);
	}
	int ans = 1;
	for(int i=1; i<=n; i++){
		if(parent[i]<0)
			ans = (ans*abs(parent[i]))%mod;
	}
	cout<<ans;
}
 
signed main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}
