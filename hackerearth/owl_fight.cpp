#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define mod 1000000007
#define int long long
 
int find(int u, int* parent){
	if(parent[u]<0)
		return u;
	return parent[u] = find(parent[u], parent);
}

void union_(int u, int v, int* parent){
	int a = find(u, parent);
	int b = find(v, parent);
	if(a!=b){
		parent[a] = min(parent[a], parent[b]);
		parent[b] = a;
	}
}

void solve(){
	int n, e; cin>>n>>e;
	int parent[n+1];
	for(int i=1; i<=n; i++){
		parent[i] = -i;
	}
	while(e--){
		int u, v; cin>>u>>v;
		union_(u, v, parent);
	}
	int q; cin>>q;
	while(q--){
		int a, b; cin>>a>>b;
		int p_a = find(a, parent);
		int p_b = find(b, parent);
		if(p_a==p_b)
			cout<<"TIE"<<endl;
		else{
			if(parent[p_a]>parent[p_b]){
				cout<<b<<endl;
			}
			else{
				cout<<a<<endl;
			}
		}
	}
}
 
signed main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}
