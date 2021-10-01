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

vector<int> prefix_function(string s){
	int n = s.size();
	vector<int> pi(n);
	for(int i=1; i<n; i++){
		int j = pi[i-1];
		while(j>0 and s[i]!=s[j])
			j = pi[j-1];
		if(s[i]==s[j])
			j++;
		pi[i] = j;
	}
	return pi;
}

void solve(){
	string s; cin>>s;
	int n; cin>>n;
	int rem = prefix_function(s)[s.size()-1];
	cout<<n*s.size()-(n-1)*rem<<endl;
}

signed main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin>>t;
	while(t--)
		solve();
}
