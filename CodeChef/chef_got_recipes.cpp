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

ll F[32];

void solve(){
	memset(F, 0, sizeof F);
	int n, mask; cin>>n;
	string s;
	for(int i=0; i<n; i++){
		mask = 0;
		cin>>s;
		for(char c: s){
			if(c=='a') mask|=1<<0;
			else if(c=='e') mask|=1<<1;
			else if(c=='i') mask|=1<<2;
			else if(c=='o') mask|=1<<3;
			else mask|=1<<4;
		}
		F[mask]++;
	}
	ll res = 0;
	for(int i=1; i<31; i++){
		for(int j=i+1; j<32; j++){
			if((i|j)==31) res += F[i]*F[j];
		}
	}
	res += F[31]*(F[31]-1)/2;
	cout<<res<<endl;
}

int main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}
