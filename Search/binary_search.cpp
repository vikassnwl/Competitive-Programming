#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define mod 1000000007
#define int long long
 
void solve(){
	int n; cin>>n;
	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	int m; cin>>m;
	int l = 0, u = n-1;
	while(l<=u){
		int mid = (l+u)/2;
		if(arr[mid]==m){
			cout<<"Found at "<<mid+1;
			return;
		}
		if(arr[mid]<m) l = mid+1;
		else u = mid-1;
	}
	cout<<"Not Found";
}
 
signed main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	//cin>>t;
	while(t--)
		solve();
}
