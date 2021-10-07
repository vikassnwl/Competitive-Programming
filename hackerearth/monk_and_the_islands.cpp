#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define mod 1000000007
#define int long long
 
void solve(){
	int n, e; cin>>n>>e;
	vector<int> tree[n+1];
	for(int i=0; i<e; i++){
		int u, v; cin>>u>>v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	int vis[n+1];
	memset(vis, 0, sizeof vis);
	int dist[n+1];
	memset(dist, 0, sizeof dist);
	queue<int> q;
	q.push(1);
	vis[1] = 1;
	while(!q.empty()){
		int node = q.front();
		q.pop();
		for(int child: tree[node]){
			if(!vis[child]){
				vis[child] = 1;
				q.push(child);
				dist[child] = dist[node]+1;
			}
		}
	}
	cout<<dist[n]<<endl;
}
 
signed main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin>>t;
	while(t--)
		solve();
}
