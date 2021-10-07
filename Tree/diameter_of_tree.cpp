#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define mod 1000000007
#define int long long
 
int max_node, max_dist;
 
void dfs(int node, int d, int* vis, vector<int>* tree){
	vis[node] = 1;
	if(d>max_dist){
		max_dist = d;
		max_node = node;
	}
	for(int child: tree[node]){
		if(!vis[child]){
			dfs(child, d+1, vis, tree);
		}
	}
}
 
void solve(){
	int n; cin>>n;
	int e = n-1;
	vector<int> tree[n+1];
	int vis[n+1];
	memset(vis, 0, sizeof vis);
	for(int i=0; i<e; i++){
		int u, v; cin>>u>>v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	max_dist = 0;
	dfs(1, 0, vis, tree);
	memset(vis, 0, sizeof vis);
	dfs(max_node, 0, vis, tree);
	cout<<max_dist;
}
 
signed main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
} 
