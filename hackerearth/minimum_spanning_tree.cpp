#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define mod 1000000007
#define int long long
 
int ans = 0;

struct edge{
	int a, b, w;
};

int find(int a, int* parent){
	if(parent[a]<0)
		return a;
	return parent[a] = find(parent[a], parent);
}

void union_(int a, int b, int* parent, int wt){
	a = find(a, parent);
	b = find(b, parent);
	if(a!=b){
		ans += wt;
		if(parent[a]<parent[b]){
			parent[a] += parent[b];
			parent[b] = a;
		}
		else{
			parent[b] += parent[a];
			parent[a] = b;
		}
	}
}

void solve(){
	int n, e; cin>>n>>e;
	edge arr[e];
	for(int i=0; i<e; i++){
		int a, b, w; cin>>a>>b>>w;
		arr[i] = {a, b, w};
	}
	sort(arr, arr+e, [](edge x, edge y){
		return x.w<y.w;
	});
	int parent[n+1];
	memset(parent, -1, sizeof parent);
	for(int i=0; i<e; i++){
		union_(arr[i].a, arr[i].b, parent, arr[i].w);
	}
	cout<<ans;
}
 
signed main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}
