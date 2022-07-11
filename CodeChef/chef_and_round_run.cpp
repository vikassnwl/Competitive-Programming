#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define mod 1000000007
#define int long long
 
void dfs(int node, vector<int>* gr, int* vis, vector<int>& order){
	vis[node] = 1;
	for(int child: gr[node]){
		if(!vis[child])
			dfs(child, gr, vis, order);
	}
	order.push_back(node);
}

void dfs1(int node, vector<int>* tr, int* vis, vector<int>& SCC){
	vis[node] = 1;
	for(int child: tr[node]){
		if(!vis[child])
			dfs1(child, tr, vis, SCC);
	}
	SCC.push_back(node);
}

void solve(){
	int n; cin>>n;
	vector<int> gr[n], tr[n];
	for(int i=0; i<n; i++){
		int x; cin>>x;
		gr[i].push_back((i+x+1)%n);
		tr[(i+x+1)%n].push_back(i);
	}
	int vis[n];
	memset(vis, 0, sizeof vis);
	vector<int> order, SCC;
	for(int i=0; i<n; i++){
		if(!vis[i])
			dfs(i, gr, vis, order);
	}
	memset(vis, 0, sizeof vis);
	int ans = 0;
	for(int i=0; i<n; i++){
		if(!vis[order[n-i-1]]){
			dfs1(order[n-i-1], tr, vis, SCC);
			if(SCC.size()!=1 or SCC[0]==gr[SCC[0]][0]){
				ans += SCC.size();
			}
			SCC.clear();
		}
	}
	cout<<ans<<endl;
}
 
signed main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin>>t;
	while(t--)
		solve();
}
