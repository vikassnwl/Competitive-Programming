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

int getHash(string key){
	int value = 0;
	int p = 31;
	int p_power = 1;

	for(char ch: key){
		value = (value+(ch-'a'+1)*p_power)%mod;
		p_power = (p_power*p)%mod;
	}
	return value;
}

void solve(){
	string key; cin>>key;
	cout<<getHash(key)<<endl;
}

signed main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}
