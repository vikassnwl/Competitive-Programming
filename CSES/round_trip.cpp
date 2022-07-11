#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define mod 1000000007
#define int long long
 
vector<int> v;
 
bool dfs(int node, int par, vector<int>* graph, int* vis){
	v.push_back(node);
	vis[node] = 1;
	for(int child: graph[node]){
		if(child==par) continue;
		if(!vis[child]){
			if(dfs(child, node, graph, vis))
				return true;
 
		}
		else{
			v.push_back(child);
			return true;
		}
	}
	v.pop_back();
	return false;
}
 
void solve(){
	int n, e; cin>>n>>e;
	vector<int> graph[n+1];
	while(e--){
		int u, v; cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	int vis[n+1];
	memset(vis, 0, sizeof vis);
	for(int i=1; i<=n; i++){
		if(!vis[i]){
			v.clear();
			if(dfs(i, -1, graph, vis)){
				int cnt = 0;
				int x = v[v.size()-1];
				int i = v.size()-2;
				vector<int> ans{x};
				while(v[i]!=x){
					ans.push_back(v[i]);
					cnt++;
					i--;
				}
				ans.push_back(x);
				cout<<cnt+2<<endl;
				for(int x: ans) cout<<x<<" ";
				return;
			}
		}	
	}
	cout<<"IMPOSSIBLE";
}
 
signed main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}
