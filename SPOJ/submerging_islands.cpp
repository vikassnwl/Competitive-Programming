#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define mod 1000000007
#define int long long
 
int n, timer;
set<int> st;

void dfs(int node, int par, vector<int>* graph, int* vis, int* in, int* low){
	vis[node] = 1;
	in[node] = low[node] = timer++;
	int children = 0;
	for(int child: graph[node]){
		if(child==par) continue;
		if(!vis[child]){
			dfs(child, node, graph, vis, in, low);
			if(low[child]>=in[node] and par!=-1)
				st.insert(node);
			low[node] = min(low[node], low[child]);
			children++;
		}
		else{
			low[node] = min(low[node], in[child]);
		}
	}
	if(par==-1 and children>1)
		st.insert(node);
}

void solve(){
	int e; cin>>e;
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
	cout<<st.size()<<endl;
	st.clear();
}
 
signed main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>n, n)
		solve();
}
