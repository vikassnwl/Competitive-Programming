#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define mod 1000000007
#define int long long
 
vector<int> ar[10001];
vector<int> res;
int in[10001];

void kahn(int n){
	priority_queue<int, vector<int>, greater<int>> q;
	for(int i=1; i<=n; i++)
		if(in[i]==0)
			q.push(i);
	while(!q.empty()){
		int curr = q.top();
		res.push_back(curr);
		q.pop();
		for(int node: ar[curr]){
			in[node]--;
			if(in[node]==0)
				q.push(node);
		}
	}
	if(res.size()==n){
		for(int node: res) cout<<node<<" ";
	}
	else cout<<"Sandro fails.";
}

void solve(){
	int n, m, x, y;
	cin>>n>>m;
	for(int i=1; i<=m; i++){
		cin>>x>>y;
		ar[x].push_back(y);
		in[y]++;
	}
	kahn(n);
}
 
signed main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}
