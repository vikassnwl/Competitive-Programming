#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define mod 1000000007
#define int long long

int par[200001];
int degree[200001];

struct edge{
	int v;
	int u;
	int w;
};

edge edges[200001];

int find(int a){
	if(par[a]==-1) return a;
	return par[a] = find(par[a]);
}

bool comp(edge a, edge b){
	if(a.w != b.w) return a.w<b.w;
	else
		if(a.v!=b.v) return a.v>b.v;
		else return a.u>b.u;
}

void merge(int a, int b){
	a = find(a);
	b = find(b);

	par[a] = b;
}

void solve(){
	int n, m; cin>>n>>m;
	for(int i=1; i<=n; i++) par[i] = -1, degree[i] = 0;
	for(int i=1; i<=m; i++){
		int a, b, w; cin>>a>>b>>edges[i].w;
		edges[i].v = min(a, b);
		edges[i].u = max(a, b);
	}
	sort(edges+1, edges+m+1, comp);
	int res = 0;
	for(int i=1; i<=m; i++){
		edge e = edges[i];
		if(find(e.v)!=find(e.u)){
			res += e.w, degree[e.v]++, degree[e.u]++;
			merge(e.v, e.u);
		}
	}
	cout<<res<<endl;
	for(int i=1; i<=n; i++) cout<<degree[i]<<" ";
	cout<<endl;
}
 
signed main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin>>t;
	while(t--)
		solve();
}
