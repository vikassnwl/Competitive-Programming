#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define mod 1000000007
#define int long long
 
bool bridge_exists;
int timer;
vector<vector<int>> edges;

void dfs(int node, int par, vector<int>* graph, int* vis, int* in, int* low){
	vis[node] = 1;
	in[node] = low[node] = timer++;
	for(int child: graph[node]){
		if(child==par) continue;
		if(!vis[child]){
			edges.push_back({node, child});
			dfs(child, node, graph, vis, in, low);
			if(low[child]>in[node]){
				bridge_exists = true;
				return;
			}
		}
		else{
			if(in[child]<in[node])
				edges.push_back({node, child});
		}
		low[node] = min(low[node], low[child]);
	}
}

void solve(){
	int n, e; cin>>n>>e;
	vector<int> graph[n+1];
	while(e--){
		int u, v; cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	int vis[n+1], in[n+1], low[n+1];
	memset(vis, 0, sizeof vis);
	for(int i=1; i<=n; i++){
		if(!vis[i])
			dfs(i, -1, graph, vis, in, low);
	}
	if(bridge_exists) cout<<0;
	else{
		for(vector<int> edge: edges){
			for(int node: edge)
				cout<<node<<" ";
			cout<<endl;
		}
	}
}
 
signed main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}
