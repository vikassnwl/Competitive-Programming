#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define mod 1000000007
#define int long long
 
int id = 0;

void dfs(int node, int* vis, vector<int>* graph, int* cc){
	cc[node] = id;
	vis[node] = 1;
	for(int child: graph[node]){
		if(!vis[child]){
			dfs(child, vis, graph, cc);
		}
	}
}

void solve(){
	int n, e;  cin>>n>>e;
	vector<int> graph[n+1];
	int vis[n+1], cc[n+1];
	memset(vis, 0, sizeof vis);
	vector<pair<int, int>> edgeList;
	for(int i=0; i<e; i++){
		int a, b; string op;
		cin>>a>>op>>b;
		if(op=="="){
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		else{
			edgeList.push_back({a, b});
		}
	}
	for(int i=1; i<=n; i++){
		if(!vis[i]){
			id++;
			dfs(i, vis, graph, cc);
		}
	}
	for(auto lst: edgeList){
		if(cc[lst.first]==cc[lst.second]){
			cout<<"NO"<<endl; return;
		}
	}
	cout<<"YES"<<endl;
}
 
signed main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin>>t;
	while(t--)
		solve();
}
