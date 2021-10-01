#include<bits/stdc++.h>
using namespace std;

//================PBDS==================
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset =
tree<T, null_type, less<T>, rb_tree_tag,
tree_order_statistics_node_update>;
//======================================

#define endl '\n'
#define mod 1000000007
#define int long long

void dfs(int node, int* visited, vector<int>* tree){
	visited[node] = 1;
	for(int child: tree[node]){
		if(!visited[child]){
			dfs(child, visited, tree);
		}
	}
}

void solve(){
	int n, e; cin>>n>>e;
	vector<int> tree[n+1];
	for(int i=0; i<e; i++){
		int u, v; cin>>u>>v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	int visited[n+1];
	memset(visited, 0, sizeof visited);
	int ans = 0;
	for(int i=1; i<=n; i++){
		if(!visited[i]){
			ans++;
			dfs(i, visited, tree);
		}
	}
	cout<<ans;
}

signed main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}
