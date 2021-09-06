#include<bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
#define INF 1000000000
#define ll long long
using namespace std;

const int maxN = 4;
set<int> tree[16], tree2[16];
int sub[16], par[16], res[16], level[16], LCA[16][maxN];

int dfs(int node, int par){
	sub[node] = 1;
	for(int child: tree[node]){
		if(child!=par) sub[node] += dfs(child, node);
	}
	return sub[node];
}

int dfs2(int node, int par, int n){
	for(int child: tree[node])
		if(child!=par and sub[child] > n/2)
			return dfs2(child, node, n);
	return node;
}

void decompose(int node, int p){
	int subTreeSize = dfs(node, p);
	int centroid = dfs2(node, p, subTreeSize);
	par[centroid] = p;
	for(int child: tree[centroid]){
		tree[child].erase(centroid), decompose(child, centroid);
	}
}

void dfs3(int node, int par, int lvl){
	level[node] = lvl;
	LCA[node][0] = par;
	for(int child: tree2[node])
		if(child!=par) dfs3(child, node, lvl+1);
}

void init(int n){
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

int dist(int a, int b){
	int lca = getLCA(a, b);
	return level[a]+level[b]-2*level[lca];
}

void update(int node){
	int cur = node;
	while(cur!=-1){
		res[cur] = min(res[cur], dist(cur, node));
		cur = par[cur];
	}
}

int query(int node){
	int cur = node;
	int ans = INF;
	while(cur!=-1){
		ans  = min(ans, res[cur]+dist(node, cur));
		cur = par[cur];
	}
	return ans;
}

int main(){	

	int n, a, b;
	cin>>n;
	for(int i=0; i<n-1; i++){
		cin>>a>>b;
		tree[a].insert(b);
		tree[b].insert(a);
	}

	for(int i=0; i<16; i++){
		tree2[i] = tree[i];
	}

	decompose(1, -1);
	for(int i=1; i<16; i++)
		res[i] = INF;
	memset(LCA, -1, sizeof LCA);
	dfs3(1, -1, 0);
	init(n);
	update(8);
	update(6);
	while(1){
		int x;
		cin>>x;
		cout<<query(x)<<endl;
	}
}
