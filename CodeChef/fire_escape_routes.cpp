#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define mod 1000000007
#define int long long

int comp_size;

void dfs(int node, int* vis, vector<int>* tree){
	vis[node] = 1;
	comp_size++;
	for(int child: tree[node]){
		if(!vis[child])
			dfs(child, vis, tree);
	}
}

void solve(){
	int n, e; cin>>n>>e;
	vector<int> tree[n+1];
	int vis[n+1];
	memset(vis, 0, sizeof vis);
	for(int i=0; i<e; i++){
		int u, v; cin>>u>>v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	int cntd_comp = 0;
	int ways = 1;
	for(int i=1; i<=n; i++){
		if(!vis[i]){
			cntd_comp++;
			comp_size = 0;
			dfs(i, vis, tree);
			ways = (ways*comp_size)%mod;
		}
	}
	cout<<cntd_comp<<" "<<ways<<endl;
}
 
signed main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin>>t;
	while(t--)
		solve();
}
