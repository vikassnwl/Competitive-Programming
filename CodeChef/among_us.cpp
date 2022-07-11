//video tutorial -> /mnt/B238844C38841191/Ubuntu Stuff/Competitive Programming



#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define mod 1000000007
#define int long long

int red, blue;

bool dfs(int u, vector<pair<int, int>>* graph, int* col){
	if(col[u]==1) red++;
	else blue++;
	for(auto val: graph[u]){
		int v = val.first, type=val.second;
		if(col[v]!=-1){
			if(type==1 and col[u]==col[v]){cout<<-1<<endl;return true;}
			if(type==2 and col[u]!=col[v]){cout<<-1<<endl;return true;}
		}
		else{
			if(type==1) col[v] = !col[u];
			else col[v] = col[u];
			if(dfs(v, graph, col)){return true;}
		}
	}
	return false;
}

void solve(){
	int n, e; cin>>n>>e;
	vector<pair<int, int>> graph[n+1];
	while(e--){
		int type, u, v; cin>>type>>u>>v;
		if(type==1){
			graph[u].push_back({v, 1});
			graph[v].push_back({u, 1});
		}
		else{
			graph[u].push_back({v, 2});
			graph[v].push_back({u, 2});
		}
	}
	int col[n+1];
	memset(col, -1, sizeof col);
	queue<int> q;
	int ans = 0;
	for(int i=1; i<=n; i++){
		if(col[i]==-1){
			col[i] = 1;
			red = 0, blue = 0;
			if(dfs(i, graph, col)){return;}
			ans += max(red, blue);
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
