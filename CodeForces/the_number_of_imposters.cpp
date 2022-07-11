#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define mod 1000000007
#define int long long
 
void solve(){
	int n, e; cin>>n>>e;
	vector<pair<int, int>> graph[n+1];
	while(e--){
		int u, v; cin>>u>>v;
		string s; cin>>s;
		if(s=="imposter"){
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
	bool isContradiction = false;
	for(int i=1; i<=n; i++){
		int numColour1 = 0;
		int numColour2 = 0;
		if(col[i]==-1){
			q.push(i);
			col[i] = 1;
			while(!q.empty()){
				int u = q.front();
				if(col[u]==1) numColour1++;
				else numColour2++;
				q.pop();
				for(auto val: graph[u]){
					int v = val.first, type=val.second;
					if(col[v]!=-1){
						if(type==1 and col[v]==col[u]) isContradiction = true;
						if(type==2 and col[v]!=col[u]) isContradiction = true;
						continue;
					}
					if(type==1) col[v] = 3-col[u];
					else col[v] = col[u];
					q.push(v);
				}
			}
			ans += max(numColour1, numColour2);
		}
	}
	if(isContradiction) cout<<-1<<endl;
	else cout<<ans<<endl;
}
 
signed main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin>>t;
	while(t--)
		solve();
}
