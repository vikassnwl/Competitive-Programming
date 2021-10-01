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

void solve(){
	int n; cin>>n;
	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	int xor_grid[n][n];
	for(int i=0; i<n; i++)
		xor_grid[0][i] = arr[i];
	for(int i=1; i<n; i++)
		for(int j=0; j<n-i; j++)
			xor_grid[i][j] = xor_grid[i-1][j]^xor_grid[i-1][j+1];
	for(int i=1; i<n; i++)
		for(int j=0; j<n-i; j++)
			xor_grid[i][j] = max(xor_grid[i][j], max(xor_grid[i-1][j], xor_grid[i-1][j+1]));
	int q; cin>>q;
	while(q--){
		int l, r; cin>>l>>r;
		l--, r--;
		cout<<xor_grid[r-l][l]<<endl;
	}
}

signed main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}
