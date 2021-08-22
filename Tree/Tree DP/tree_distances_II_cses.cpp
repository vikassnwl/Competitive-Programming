#include<bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
#define ll long long
using namespace std;

void dfs1(int node, int par, vector<vector<int>> &tree, vector<ll> &subDist, vector<int> &subSize, vector<ll> &res){
	subSize[node] = 1;
	for(int child: tree[node]){
		if(child!=par){
			dfs1(child, node, tree, subDist, subSize, res);
			subSize[node] += subSize[child];
			subDist[node] += subSize[child]+subDist[child];
		}
	}
}

void dfs(int node, int par, vector<vector<int>> &tree, vector<ll> &subDist, vector<int> &subSize, vector<ll> &res, int n){
	res[node] = res[par]-subSize[node]-subDist[node]+n-subSize[node]+subDist[node];
	for(int child: tree[node]){
		if(child!=par){
			dfs(child, node, tree, subDist, subSize, res, n);
		}
	}
}

int main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin>>n;
	vector<vector<int>> tree(n+1);
	for(int i=0; i<n-1; i++){
		int a, b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	vector<ll> res(n+1);
	vector<ll> subDist(n+1);
	vector<int> subSize(n+1);
	dfs1(1, -1, tree, subDist, subSize, res);
	res[1] = subDist[1];
	for(int child: tree[1]){
		dfs(child, 1, tree, subDist, subSize, res, n);
	}
	for(int i=1; i<=n; i++){
		cout<<res[i]<<" ";
	}
}
