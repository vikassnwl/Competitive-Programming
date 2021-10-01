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

void solve(){
	int n; cin>>n;
	int arr[n+1], dp[n+1]{};
	for(int i=1; i<=n; i++) cin>>arr[i];
	for(int i=1; i<=n; i++)
		dp[i] = max(dp[i-1], 0)+arr[i];
	int ans = *max_element(dp, dp+n+1);
	cout<<(ans<0?0:ans);
}

int main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}
