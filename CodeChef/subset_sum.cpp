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
	int n, sum; cin>>n>>sum;
	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	bool dp[n+1][sum+1];
	dp[0][0] = 1;
	for(int i=1; i<=sum; i++) dp[0][i] = 0;
	for(int i=1; i<=n; i++){
		for(int j=0; j<=sum; j++){
			if(j<arr[i-1]) dp[i][j] = dp[i-1][j];
			else{
				if(dp[i-1][j]==1 or dp[i-1][j-arr[i-1]]==1)
					dp[i][j] = 1;
				else dp[i][j] = 0;
			}
		}
	}
	cout<<dp[n][sum]<<endl;
}

int main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}
