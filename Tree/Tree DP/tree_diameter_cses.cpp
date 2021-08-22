#include<bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
#define ll long long
using namespace std;

void dfs(int node, int par, vector<vector<int>> &tree, vector<int> &f, vector<int> &g, int &ans){
	vector<int> childList;
	for(int child: tree[node]){
		if(child!=par){
			dfs(child, node, tree, f, g, ans);
			f[node] = max(f[node], f[child]+1);
			childList.push_back(f[child]);
		}
	}
	ans = max(ans, f[node]);
	if(childList.size()>1){
		sort(childList.rbegin(), childList.rend());
		g[node] = 2+childList[0]+childList[1];
		ans = max(ans, g[node]);
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
	int ans = 0;
	vector<int> f(n+1);
	vector<int> g(n+1);
	dfs(1, -1, tree, f, g, ans);
	cout<<ans;
}
