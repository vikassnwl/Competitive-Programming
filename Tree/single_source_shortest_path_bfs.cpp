#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define mod 1000000007
#define int long long
 
void solve(){
	int n; cin>>n;
	int e = n-1;
	vector<int> tree[n+1];
	for(int i=0; i<e; i++){
		int u, v; cin>>u>>v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	int vis[n+1];
	memset(vis, 0, sizeof vis);
	int dist[n+1];
	queue<int> q;
	cout<<"Enter source node: ";
	int src; cin>>src;
	q.push(src);
	vis[src] = 1;
	dist[src] = 0;
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
	for(int i=1; i<=n; i++) cout<<dist[i]<<" ";
}
 
signed main(){	
	solve();
}
