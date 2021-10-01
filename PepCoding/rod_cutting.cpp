#include<bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
#define ll long long
using namespace std;

//================PBDS==================
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset =
tree<T, null_type, less<T>, rb_tree_tag,
tree_order_statistics_node_update>;
//======================================

int dp[2000][2000];

int ks(int w, int wt[], int val[], int n){
	if(n==0||w==0) return 0;
	if(dp[n-1][w-1]==-1){
		int exc = ks(w, wt, val, n-1);
		if(wt[n-1]<=w){
			int inc = val[n-1]+ks(w-wt[n-1], wt, val, n);
			dp[n-1][w-1] = max(inc, exc);
		}
		else dp[n-1][w-1] = exc;
	}
	return dp[n-1][w-1];
}

void solve(){
	memset(dp, -1, sizeof dp);
	int n; cin>>n;
	int wt[n], val[n];
	for(int i=1; i<=n; i++) wt[i-1] = i;
	for(int i=0; i<n; i++) cin>>val[i];
	cout<<ks(n, wt, val, n);
}

int main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}
