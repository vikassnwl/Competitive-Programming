#include<bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define mod 1000000007
#define int long long
 
void solve(){
	int n, k; cin>>n>>k;
	int arr[n];
	for(int i=0; i<n; i++) cin>>arr[i];
	vector<int> d;
	for(int i=2; i*i<=k; i++){
		if(k%i==0){
			d.push_back(i);
			if(i!=k/i) d.push_back(k/i);
		}
	}
	map<int, int> mp;
	int j = 1;
	int ans = 0;
	for(int i=0; i<n; i++){
		if(arr[i]%k==0){
			ans += n-j;
			j++;
		}
		else{
			ans += mp[k/__gcd(arr[i], k)];
			for(int x: d){
				if(arr[i]%x==0){
					mp[x]++;
				}
			}
		}
	}
	cout<<ans;
}
 
signed main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	//cin>>t;
	while(t--)
		solve();
}
