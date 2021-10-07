#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define mod 1000000007
#define int long long
 
vector<int> ar[1001];
vector<int> tr[1001];

vector<int> order;
vector<int> SCC;

int vis[1001];

void dfs(int node){
	vis[node] = 1;
	for(int child: ar[node]){
		if(vis[child]==0)
			dfs(child);
	}
	order.push_back(node);
}

void dfs1(int node){
	vis[node] = 1;
	for(int child: tr[node])
		if(vis[child] == 0)
			dfs1(child);
	SCC.push_back(node);
}

void solve(){
	int n, a, b, m;
	cin>>n>>m;
	for(int i=1; i<=n; i++)
		ar[i].clear(), tr[i].clear(), vis[i] = 0;
	order.clear();

	for(int i=1; i<=m; i++){
		cin>>a>>b;
		ar[a].push_back(b);
		tr[b].push_back(a);
	}
	for(int i=1; i<=n; i++){
		if(vis[i]==0) dfs(i);
	}
	for(int i=1; i<=n; i++)
		vis[i] = 0;
	for(int i=1; i<=n; i++)
		if(vis[order[n-i]]==0){
			SCC.clear();
			dfs1(order[n-i]);
			cout<<"dfs1() called from "<<order[n-i]<<" and printing SCC"<<endl;
			for(int node: SCC)
				cout<<node<<" ";
			cout<<endl;
		}
}
 
signed main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin>>t;
	while(t--)
		solve();
}
