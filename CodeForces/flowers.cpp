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
#define mod 1000000007
#define int long long

int k, pre[100001], dp[100001];

int getAns(int n){
	if(n==0) return 1;
	if(dp[n]!=-1) return dp[n];
	int ans = 0;
	if(n>=k)
		ans += getAns(n-k);
	ans += getAns(n-1);
	return dp[n] = ans%mod;
}

void solve(){
	int a, b; cin>>a>>b;
	cout<<(pre[b]-pre[a-1]+mod)%mod<<endl;
}

signed main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(dp, -1, sizeof dp);
	int t; cin>>t>>k;
	for(int i=1; i<=100000; i++)
		pre[i] = (pre[i-1]+getAns(i))%mod;
	while(t--)
		solve();
}
