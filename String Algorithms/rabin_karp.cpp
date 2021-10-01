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

int getHash(string s){
	int value = 0;
	int p = 31;
	int p_power = 1;
	for(char c: s){
		value = (value+(c-'a'+1)*p_power)%mod;
		p_power = (p_power*p)%mod;
	}
	return value;
}

int dp[1000001], pow_[1000001];

void init(string s){
	int p = 31;
	int p_power = 1;
	pow_[0] = 1;
	dp[0] = (s[0]-'a'+1)%mod;
	for(int i=1; i<s.size(); i++){
		p_power = (p_power*p)%mod;
		pow_[i] = p_power;
		dp[i] = (dp[i-1]+(s[i]-'a'+1)*p_power)%mod;
	}
}

void solve(){
	int n; cin>>n;
	string needle, haystack; cin>>needle>>haystack;
	int needle_hash = getHash(needle);
	init(haystack);
	for(int L=0, R=n-1; R<haystack.size(); L++, R++){
		if((needle_hash*pow_[L])%mod==(dp[R]-(L>0?dp[L-1]:0)+mod)%mod)
			cout<<L<<endl;
	}
	cout<<endl;
}

signed main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(cin)
		solve();
}
