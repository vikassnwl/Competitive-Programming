#include<bits/stdc++.h>
using namespace std;

//================PBDS==================
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset =
tree<T, null_type, less<T>, rb_tree_tag,
tree_order_statistics_node_update>;
//======================================

#define endl '\n'
#define mod 998244353
#define int long long

int dp[1000001], divcnt[1000001];

void solve(){
	int n, sum=1; cin>>n;
	for(int i=1; i<=n; i++)
		for(int j=i+i; j<=n; j+=i)
			divcnt[j]++;
	for(int i=1; i<=n; i++){
		dp[i] = (sum+divcnt[i])%mod;
		sum = (sum+dp[i])%mod;
	}
	cout<<dp[n];
}

signed main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}
