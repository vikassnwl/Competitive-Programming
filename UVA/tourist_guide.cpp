#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define mod 1000000007
#define int long long
 
int n, timer, idx;
string cities[100];
set<string> st;

void dfs(int node, int par, vector<int>* graph, int* vis, int* in, int* low){
	vis[node] = 1;
	in[node] = low[node] = timer++;
	int children = 0;
	for(int child: graph[node]){
		if(child==par) continue;
		if(!vis[child]){
			dfs(child, node, graph, vis, in, low);
			if(low[child]>=in[node] and par!=-1)
				st.insert(cities[node]);
			low[node] = min(low[node], low[child]);
			children++;
		}
		else{
			low[node] = min(low[node], in[child]);
		}
	}
	if(par==-1 and children>1)
		st.insert(cities[node]);
}

void solve(){
	if(idx>0) cout<<endl;
	map<string, int> mp;
	for(int i=0; i<n; i++){
		string s; cin>>s;
		mp[s] = i;
		cities[i] = s;
	}
	int e; cin>>e;
	vector<int> graph[n];
	while(e--){
		string u, v; cin>>u>>v;
		graph[mp[u]].push_back(mp[v]);
		graph[mp[v]].push_back(mp[u]);
	}
	int vis[n], in[n], low[n];
	memset(vis, 0, sizeof vis);
	for(int i=0; i<n; i++){
		if(!vis[i])
			dfs(i, -1, graph, vis, in, low);
	}

	cout<<"City map #"<<++idx<<": "<<st.size()<<" camera(s) found"<<endl;
	for(string s: st) cout<<s<<endl;
	st.clear();
}
 
signed main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(cin>>n, n)
		solve();
}
