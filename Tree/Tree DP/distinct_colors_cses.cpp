#include<bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
#define ll long long
using namespace std;
 
void dfs(int node, int par, vector<vector<int>> &tree, vector<set<int>*> &st, vector<int> &c, vector<int> &res){
	int mx = 0;
	int mxNode = -1;
	for(int child: tree[node]){
		if(child!=par){
			dfs(child, node, tree, st, c, res);
			if(st[child]->size()>mx) mx=st[child]->size(), mxNode=child;
		}
	}
	if(mxNode==-1) st[node]=new set<int>();
	else st[node]=st[mxNode];
 
	st[node]->insert(c[node]);
 
	for(int child: tree[node]){
		if(child!=par and child!=mxNode){
			for(int color: *st[child]){
				st[node]->insert(color);
			}
		}
	}
	res[node] = st[node]->size();
}
 
int main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	int n;
	cin>>n;
	vector<int> c(n+1);
	for(int i=1; i<=n; i++){
		cin>>c[i];
	}
	vector<vector<int>> tree(n+1);
	for(int i=0; i<n-1; i++){
		int a, b;
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	vector<int> res(n+1);
	vector<set<int>*> st(n+1);
	dfs(1, -1, tree, st, c, res);
	for(int i=1; i<=n; i++){
		cout<<res[i]<<" ";
	}
}
