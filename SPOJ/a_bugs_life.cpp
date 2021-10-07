#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define mod 1000000007
#define int long long
 
bool dfs(int node, int c, int* vis, int* col, vector<int>* tree){
	vis[node] = 1;
	col[node] = c;
	for(int child: tree[node]){
		if(!vis[child]){
			if(dfs(child, c^1, vis, col, tree)==false)
				return false;
		}
		else{
			if(col[node]==col[child])
				return false;
		}
	}
	return true;
}

void solve(int tc){
	int n, e; cin>>n>>e;
	vector<int> tree[n+1];
	int col[n+1], vis[n+1];
	memset(vis, 0, sizeof vis);
	for(int i=0; i<e; i++){
		int u, v; cin>>u>>v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	cout<<"Scenario #"<<tc<<":"<<endl;
	for(int i=1; i<=n; i++){
		if(!vis[i]){
			if(!dfs(i, 0, vis, col, tree)){
				cout<<"Suspicious bugs found!"<<endl;
				return;
			}
		}
	}
	cout<<"No suspicious bugs found!"<<endl;
}
 
signed main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin>>t;
	for(int tc=1; tc<=t; tc++)
		solve(tc);
}
