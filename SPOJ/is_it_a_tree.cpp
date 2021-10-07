#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define mod 1000000007
#define int long long
 
void dfs(int node, int* vis, vector<int>* tree){
	vis[node] = 1;
	for(int child: tree[node]){
		if(!vis[child]){
			dfs(child, vis, tree);
		}
	}
}

void solve(){
	int n, e; cin>>n>>e;
	if(e!=n-1){cout<<"NO";return;}
	vector<int> tree[n+1];
	int vis[n+1];
	memset(vis, 0, sizeof vis);
	for(int i=0; i<e; i++){
		int u, v; cin>>u>>v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	int cnt = 0;
	for(int i=1; i<=n; i++){
		if(!vis[i]){
			if(++cnt>1){cout<<"NO";return;}
			dfs(i, vis, tree);
		}
	}
	cout<<"YES";
}
 
signed main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}
