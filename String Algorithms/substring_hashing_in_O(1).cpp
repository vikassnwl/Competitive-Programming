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

int dp[1000001], inv[1000001];

int power(int a, int n){
	int result = 1;
	while(n){
		if(n&1) result = (result*a)%mod;
		n>>=1;
		a = (a*a)%mod;
	}
	return result;
}

void init(string input_string){
	int p = 31;
	int p_power = 1;
	inv[0] = 1;
	dp[0] = (input_string[0]-'a'+1);

	for(int i=1; i<input_string.size(); i++){
		char ch = input_string[i];
		p_power = (p_power*p)%mod;
		inv[i] = power(p_power, mod-2);
		dp[i] = (dp[i-1]+(ch-'a'+1)*p_power)%mod;
	}
}

int substringHash(int L, int R){
	int result = dp[R];
	if(L>0) result -= dp[L-1];
	result = (result*inv[L])%mod;
	return result;
}

void solve(){
	string input_string;
	int tc, L, R;
	cin>>input_string;
	init(input_string);

	cin>>tc;
	while(tc--){
		cin>>L>>R;
		cout<<substringHash(L, R)<<endl;
	}
}

signed main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}
