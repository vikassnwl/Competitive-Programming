//Problem link -> https://www.spoj.com/problems/GOT/
#include<bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
#define ll long long
using namespace std;
 
const int N = 100001, maxN = 17, BLK = 700;
int val[N], timer, LCA[N][maxN], level[N], S[N], T[N], FT[2*N], eleF[N], nodeF[N], res[2*N];
vector<int> tree[N];
 
void dfs(int node, int par, int lvl){
	level[node] = lvl;
	LCA[node][0] = par;
	S[node] = timer;
	FT[timer] = node;
	timer++;
	for(int child: tree[node])
		if(child!=par) dfs(child, node, lvl+1);
	T[node] = timer;
	FT[timer] = node;
	timer++;
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
 
struct query{
	int l;
	int r;
	int c;
	int lca;
	int idx;
};
 
query Q[2*N];
 
int getLCA(int a, int b){
	if(level[a]>level[b]) swap(a, b);
	int d = level[b]-level[a];
	while(d){
		int i = log2(d);
		b = LCA[b][i];
		d -= 1<<i;
	}
	if(a==b) return a;
	for(int j=maxN-1; j>=0; j--){
		if(LCA[a][j]!=-1 and LCA[a][j]!=LCA[b][j]){
			a = LCA[a][j];
			b = LCA[b][j];
		}
	}
	return LCA[a][0];
}
 
bool comp(query a, query b){
	if(a.l/BLK!=b.l/BLK) return a.l/BLK<b.l/BLK;
	return a.r<b.r;
}
 
void add(int idx){
	int node = FT[idx];
	nodeF[node]++;
 
	int c = val[node];
	if(nodeF[node]==1)
		eleF[c]++;
	else eleF[c]--;
}
 
void remove(int idx){
	int node = FT[idx];
	nodeF[node]--;
 
	int c = val[node];
	if(nodeF[node]==1)
		eleF[c]++;
	else eleF[c]--;
}
 
int main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int n, q, a, b, c;
	while(cin>>n){
		cin>>q;
		for(int i=0; i<=n; i++)
			tree[i].clear(), nodeF[i] = 0, eleF[i] = 0;
		for(int i=0; i<q; i++)
			res[i] = 0;
		for(int i=1; i<=n; i++)
			cin>>val[i];
		for(int i=0; i<n-1; i++){
			cin>>a>>b;
			tree[a].push_back(b);
			tree[b].push_back(a);
		}
		timer = 1;
		memset(LCA, -1, sizeof LCA);
		dfs(1, -1, 0);
		init(n);
		for(int i=0; i<q; i++){
			cin>>a>>b>>c;
			Q[i].idx = i;
			Q[i].c = c;
			int lca = getLCA(a, b);
			if(S[a]>S[b]) swap(a, b);
			if(a==lca)
				Q[i].l = S[a], Q[i].r = S[b], Q[i].lca = -1;
			else Q[i].l = T[a], Q[i].r = S[b], Q[i].lca = lca;
		}
		sort(Q, Q+q, comp);
		int ML = 1, MR = 0;
		for(int i=0; i<q; i++){
			int L = Q[i].l;
			int R = Q[i].r;
			int idx = Q[i].idx;
			c = Q[i].c;
			int lca = Q[i].lca;
 
			while(MR<R)
				MR++, add(MR);
			while(MR>R)
				remove(MR), MR--;
			while(ML<L)
				remove(ML), ML++;
			while(ML>L)
				ML--, add(ML);
 
			if(eleF[c]>0)
				res[idx] = 1;
			if(lca!=-1 and val[lca]==c)
				res[idx] = 1;
		}
		for(int i=0; i<q; i++)
			cout<<(res[i]?"Find":"NotFind")<<endl;
		cout<<endl;
	}
}
