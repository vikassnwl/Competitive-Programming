#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define mod 1000000007
#define int long long
 
int dfs(int node, int* vis, vector<int>* tree, int* subSize){
	int size = 1;
	vis[node] = 1;
	for(int child: tree[node]){
		if(!vis[child]){
			size += dfs(child, vis, tree, subSize);
		}
	}
	return subSize[node] = size;
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
	int subSize[n+1];
	memset(subSize, 0, sizeof subSize);
	dfs(1, vis, tree, subSize);
	for(int i=1; i<=n; i++)
		cout<<subSize[i]<<" ";
}
 
signed main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}
