#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define mod 1000000007
#define int long long

int n, max_size=INT_MAX;

int find(int u, int* parent){
	if(parent[u]<0)
		return u;
	return parent[u] = find(parent[u], parent);
}

void union_(int u, int v, int* parent){
	u = find(u, parent);
	v = find(v, parent);
	if(u!=v){
		n--;
		if(parent[u]<parent[v]){
			parent[u] += parent[v];
			max_size = min(max_size, parent[u]);
			parent[v] = u;
		}
		else{
			parent[v] += parent[u];
			max_size = min(max_size, parent[v]);
			parent[u] = v;
		}
	}
}

void solve(){
	int e; cin>>n>>e;
	int parent[n+1];
	memset(parent, -1, sizeof parent);
	while(e--){
		int u, v; cin>>u>>v;
		union_(u, v, parent);
		cout<<n<<" "<<abs(max_size)<<endl;
	}
}
 
signed main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}
