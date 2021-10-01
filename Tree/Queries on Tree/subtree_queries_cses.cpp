#include<bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
#define ll long long
using namespace std;

const int N = 200001;
ll val[N], sub[N], in[N], timer=0, ar[N], st[4*N];
vector<int> tree[N];

void dfs(int node, int par){
	sub[node] = 1;
	in[node] = ++timer;
	ar[timer] = val[node];
	for(int child: tree[node])
		if(child!=par) dfs(child, node), sub[node] += sub[child];
}

void build(int si, int ss, int se){
	if(ss==se){
		st[si] = ar[ss];
		return;
	}
	int mid = (ss+se)/2;
	build(2*si, ss, mid);
	build(2*si+1, mid+1, se);
	st[si] = st[2*si]+st[2*si+1];
}

void update(int si, int ss, int se, int qi, int dx){
	if(ss>qi or se<qi) return;
	if(ss==se){
		st[si] += dx;
		return;
	}
	int mid = (ss+se)/2;
	update(2*si, ss, mid, qi, dx);
	update(2*si+1, mid+1, se, qi, dx);
	st[si] = st[2*si]+st[2*si+1];
}

ll getSum(int si, int ss, int se, int qs, int qe){
	if(ss>qe or se<qs) return 0;
	if(ss>=qs and se<=qe) return st[si];
	int mid = (ss+se)/2;
	ll L = getSum(2*si, ss, mid, qs, qe);
	ll R = getSum(2*si+1, mid+1, se, qs, qe);
	return L+R;	
}

int main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, q, a, b;
	cin>>n>>q;
	for(int i=1; i<=n; i++)
		cin>>val[i];
	for(int i=0; i<n-1; i++){
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	dfs(1, -1);
	build(1, 1, n);
	int t;
	while(q--){
		cin>>t;
		if(t==1){
			cin>>a>>b;
			update(1, 1, n, in[a], b-ar[in[a]]);
			ar[in[a]] = b;
		}
		else{
			cin>>a;
			cout<<getSum(1, 1, n, in[a], in[a]+sub[a]-1)<<endl;
		}
	}
}
