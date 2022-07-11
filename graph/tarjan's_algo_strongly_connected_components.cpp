#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define mod 1000000007
#define int long long
 
int timer, SCC;

void dfs(int node, vector<int>* graph, int* vis, stack<int>& st, int* onStack, int* in, int* low){
	vis[node] = 1;
	in[node] = low[node] = timer++;
	st.push(node);
	onStack[node] = 1;
	for(int child: graph[node]){
		if(!vis[child]){
			dfs(child, graph, vis, st, onStack, in, low);
			if(onStack[child])
				low[node] = min(low[node], low[child]);
		}
		else if(onStack[child]){
			low[node] = min(low[node], in[child]);
		}
	}
	if(in[node]==low[node]){
		SCC++;
		cout<<"SCC #"<<SCC<<endl;
		int u;
		while(1){
			u = st.top();
			st.pop(), onStack[u] = 0;
			cout<<u<<" ";
			if(u==node) break;
		}
		cout<<endl;
	}
}

void solve(){
	int n, e; cin>>n>>e;
	vector<int> graph[n+1];
	while(e--){
		int u, v; cin>>u>>v;
		graph[u].push_back(v);
	}
	int vis[n+1], onStack[n+1], in[n+1], low[n+1];
	memset(vis, 0, sizeof vis);
	memset(onStack, 0, sizeof onStack);
	stack<int> st;
	for(int i=1; i<=n; i++){
		if(!vis[i])
			dfs(i, graph, vis, st, onStack, in, low);
	}
}
 
signed main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}
