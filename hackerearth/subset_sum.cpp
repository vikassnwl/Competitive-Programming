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
	int n, sum; cin>>n>>sum;
	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	sort(arr, arr+n);
	set<vector<int>> v2;
	for(int i=0; i<1<<n; i++){
		int k = 0;
		vector<int> v;
		for(int j=0; j<n; j++){
			if(1<<j&i) v.push_back(arr[j]), k+=arr[j];
		}
		if(sum==k) v2.insert(v);
	}
	for(vector<int> x: v2){
		for(int y: x) cout<<y<<" ";
		cout<<endl;
	}
}

int main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}
