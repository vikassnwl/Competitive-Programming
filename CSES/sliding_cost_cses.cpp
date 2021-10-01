#include<bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
#define ll long long
using namespace std;
 
//==================PBDS====================
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
//==========================================
 
void solve(){
	int n, k;
	cin>>n>>k;
	int arr[n];
	for(int i=0; i<n; i++)
		cin>>arr[i];
 
	oset<int> s;
	for(int i=0; i<k; i++)
		s.insert(arr[i]);
 
	int old_m = *s.find_by_order((k+1)/2-1);
	ll d = 0;
	for(int i=0; i<k; i++)
		d += abs(arr[i]-old_m);
 
	cout<<d<<" ";
 
	for(int i=0; i<n-k; i++){
		s.erase(s.find_by_order(s.order_of_key(arr[i])));
		s.insert(arr[i+k]);
 
		int m = *s.find_by_order((k+1)/2-1);
		d += abs(arr[i+k]-m)-abs(arr[i]-old_m);
		if(k%2==0) d -= m-old_m;
		old_m = m;
		cout<<d<<" ";
	}
}
 
int main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}
