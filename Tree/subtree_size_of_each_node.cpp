#include<bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
#define ll long long
using namespace std;

int sub[100];
vector<int> tree[100];

int dfs(int node, int par){
	sub[node] = 1;
	for(int child: tree[node])
		if(child!=par) sub[node] += dfs(child, node);
	return sub[node];
}

int main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, a, b;
	cin>>n;
	for(int i=0; i<n-1; i++){
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	dfs(1, -1);
	for(int x: sub)
		cout<<x<<endl;

}
