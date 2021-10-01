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
	int arr[4];
	for(int i=0; i<4; i++)
		cin>>arr[i];
	for(int i=1; i<1<<4; i++){
		int sum_ = 0;
		for(int j=0; j<4; j++){
			if(1<<j&i) sum_ += arr[j];
		}
		if(sum_==0){cout<<"Yes"<<endl;return;}
	}
	cout<<"No"<<endl;
}

int main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
