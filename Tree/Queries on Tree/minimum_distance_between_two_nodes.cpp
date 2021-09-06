#include<bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
#define ll long long
using namespace std;

const int N = 1001, maxN = 11;
int LCA[N][maxN], level[N];
vector<int> tree[N];

void dfs(int node, int par, int lvl){
	level[node] = lvl;
	LCA[node][0] = par;
	for(int child: tree[node])
		if(child!=par) dfs(child, node, lvl+1);
}

void init(int n){
	dfs(1, -1, 0);
	for(int j=1; j<maxN; j++){
		for(int i=1; i<=n; i++){
			if(LCA[i][j-1]!=-1){
				int par = LCA[i][j-1];
				LCA[i][j] = LCA[par][j-1];
			}
		}
	}
}

int getLCA(int a, int b){
	if(level[a]>level[b]) swap(a, b);
	int d = level[b]-level[a];
	while(d){
		int i = log2(d);
		b = LCA[b][i];
		d -= 1<<i;
	}
	if(a==b) return a;
	for(int i=maxN-1; i>=0; i--){
		if(LCA[a][i]!=-1 and LCA[a][i]!=LCA[b][i]){
			a = LCA[a][i];
			b = LCA[b][i];
		}
	}
	return LCA[a][0];
}

int getDist(int a, int b){
	int lca = getLCA(a, b);
	return level[a]+level[b]-2*level[lca];
}

int main(){	
	int n, q, a, b;
	cin>>n;
	for(int i=0; i<n-1; i++){
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	memset(LCA, -1, sizeof LCA);
	init(n);
	cin>>q;
	while(q--){
		cin>>a>>b;
		cout<<getDist(a, b)<<endl;
	}
}
