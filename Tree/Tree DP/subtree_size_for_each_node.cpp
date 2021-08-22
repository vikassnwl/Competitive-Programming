#include<bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
#define ll long long
using namespace std;

void dfs(int node, int par, vector<vector<int>> &tree, vector<int> &sub){
	sub[node] = 1;
	for(int child: tree[node]){
		if(child!=par){
			dfs(child, node, tree, sub);
			sub[node] += sub[child];
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
	vector<int> sub(n+1);
	dfs(1, -1, tree, sub);
	for(int x: sub){
		cout<<x<<endl;
	}
}
