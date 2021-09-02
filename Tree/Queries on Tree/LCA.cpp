#include<bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
#define ll long long
using namespace std;

vector<int> tree[10];
int par[10];

void build_par(int node, int par_){
	par[node] = par_;
	for(int child: tree[node]){
		if(child!=par_) build_par(child, node);
	}
}

int level(int tar){
	queue<pair<int, int>> q({{1, -1}});
	int node, par, depth = 0, q_size;
	while(!q.empty()){
		q_size = q.size();
		for(int i=0; i<q_size; i++){
			tie(node, par) = q.front();
			if(node==tar) return depth;
			q.pop();
			for(int child: tree[node])
				if(child!=par) q.push({child, node});
		}
		depth++;
	}
	return 0;
}

int LCA(int a, int b){
	int d = level(b)-level(a);
	while(d>0){
		b = par[b];
		d--;
	}
	if(a==b) return a;
	while(par[a]!=par[b]){
		a = par[a];
		b = par[b];
	}
	return par[a];
}

int main(){	


	int n, a, b;
	cin>>n;
	for(int i=0; i<n-1; i++){
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	
	build_par(1, -1);
	while(true){
	cin>>a>>b;
	if(level(a)>level(b)){
		int temp = a;
		a = b;
		b = temp;	
	}
	cout<<LCA(a, b)<<endl;
	}
}
