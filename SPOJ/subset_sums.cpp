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
	int n, a, b; cin>>n>>a>>b;
	int arr1[n/2], arr2[n-n/2];
	for(int i=0; i<n/2; i++) cin>>arr1[i];
	for(int i=0; i<n-n/2; i++) cin>>arr2[i];

	int arr3[1<<n/2], arr4[1<<n-n/2];
	for(int i=0; i<1<<n/2; i++){
		int sum = 0;
		for(int j=0; j<n/2; j++){
			if(1<<j&i) sum += arr1[j];
		}
		arr3[i] = sum;
	}

	for(int i=0; i<1<<n-n/2; i++){
		int sum = 0;
		for(int j=0; j<n-n/2; j++){
			if(1<<j&i) sum += arr2[j];
		}
		arr4[i] = sum;
	}

	sort(arr4, arr4+(1<<n-n/2));
	ll ans = 0;
	for(int i=0; i<1<<n/2; i++){
		int lb = lower_bound(arr4, arr4+(1<<n-n/2), a-arr3[i])-arr4;
		int ub = upper_bound(arr4, arr4+(1<<n-n/2), b-arr3[i])-arr4;
		ans += ub-lb;
	}
	cout<<ans;
}

int main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}
