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

int arr[11], dp[11][91][2];

int getAns(int pos, int n, int sum, bool flag){
	if(pos>n) return sum;
	if(dp[pos][sum][flag]!=-1) return dp[pos][sum][flag];
	int limit = 9;
	if(!flag) limit = arr[pos];
	int ans = 0;
	for(int i=0; i<=limit; i++)
		if(flag||i<limit)
			ans += getAns(pos+1, n, sum+i, true);
		else ans += getAns(pos+1, n, sum+i, false);
	return dp[pos][sum][flag] = ans;
}

void solve(){
	while(1){
		string s, t; cin>>s>>t;
		if(s=="-1" and t=="-1") break;
		s = to_string(stoi(s)-1);
		memset(dp, -1, sizeof dp);
		for(int i=1; i<=s.size(); i++)
			arr[i] = s[i-1]-48;
		int L = getAns(1, s.size(), 0, 0);
		memset(dp, -1, sizeof dp);
		for(int i=1; i<=t.size(); i++)
			arr[i] = t[i-1]-48;
		int R = getAns(1, t.size(), 0, 0);
		cout<<R-L<<endl;
	}
}

signed main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}
