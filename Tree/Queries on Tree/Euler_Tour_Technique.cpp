#include<bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
#define ll long long
using namespace std;

vector<int> tree[100];
int S[100], T[100], FT[200];
int timer;

void dfs(int node, int par){
	S[node] = timer;
	FT[timer] = node;
	timer++;

	for(int child: tree[node]){
		if(child!=par){
			dfs(child, node);
		}
	}

	T[node] = timer;
	FT[timer] = node;
	timer++;
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
	timer = 1;	
	dfs(1, -1);

	cout<<"S = {";
	for(int i=1; i<=n; i++){
		cout<<S[i]<<", ";
	}
	cout<<"}"<<endl;

	cout<<"T = {";
	for(int i=1; i<=n; i++){
		cout<<T[i]<<", ";
	}
	cout<<"}"<<endl;

	cout<<"FT = {";
	for(int i=1; i<=2*n; i++){
		cout<<FT[i]<<", ";
	}
	cout<<"}"<<endl;

}
