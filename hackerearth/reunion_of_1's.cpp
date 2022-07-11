#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define mod 1000000007
#define int long long
 
int rank_[100001];
int par[100001];
char ar[100010];

int find(int a){
	if(par[a]==-1)
		return a;
	return find(par[a]);
}

void merge(int a, int b){
	a = find(a);
	b = find(b);
	if(a==b) return;
	if(rank_[a]>rank_[b]){
		rank_[a] += rank_[b];
		par[b] = a;
	}
	else{
		rank_[b] += rank_[a];
		par[a] = b;
	}
}

void solve(){
	int n, k, a; cin>>n>>k;
	int mx = 0;
	for(int i=1; i<=n; i++){
		cin>>ar[i];
		if(ar[i]=='1'){
			par[i] = -1;
			rank_[i] = 1;
			if(i>1 and ar[i-1]=='1') merge(i, i-1);
			int p = find(i);
			if(rank_[p]>mx)
				mx = rank_[p];
		}
	}
	while(k--){
		cin>>a;
		if(a==1)
			cout<<mx<<endl;
		else{
			cin>>a;
			if(ar[a] == '1') continue;
			else{
				ar[a] = '1';
				par[a] = -1;
				rank_[a] = 1;
				if(a>1 and ar[a-1] == '1') merge(a, a-1);
				if(a<n and ar[a+1] == '1') merge(a, a+1);
				int p = find(a);
				if(rank_[p]>mx)
					mx = rank_[p];
			}
		}
	}
}
 
signed main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}
