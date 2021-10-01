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

int divcnt[1001];

void solve(){
	int n; cin>>n;
	for(int i=1; i<=n; i++)
		for(int j=i; j<=n; j+=i)
			divcnt[j]++;
	for(int i=1; i<=n; i++) cout<<i<<"->"<<divcnt[i]<<endl;
}

signed main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}
