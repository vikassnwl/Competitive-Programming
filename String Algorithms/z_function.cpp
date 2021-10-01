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

vector<int> z_function(string s){
	int n = s.size();
	vector<int> z(n);
	for(int i=1, l=0, r=0; i<n; i++){
		if(i<=r)
			z[i] = min(r-i+1, z[i-l]);
		while(i+z[i]<n and s[z[i]]==s[i+z[i]])
			z[i]++;
		if(i+z[i]-1>r)
			l = i, r = i+z[i]-1;
	}
	return z;
}

void solve(){
	string s; cin>>s;
	for(int x: z_function(s)) cout<<x<<" ";
	cout<<endl;
}

signed main(){	
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	while(1)
		solve();
}
