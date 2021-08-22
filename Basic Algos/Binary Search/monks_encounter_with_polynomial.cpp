#include<bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
#define ll long long
using namespace std;

ll F(int a, int b, int c, int x){
	return 1ll*a*x*x+1ll*b*x+c;
}

int solve(int a, int b, int c, ll k){
	if(c>=k) return 0;
	int l = 1, u = ceil(sqrt(k));
	while(l<=u){
		int mid = (l+u)/2;
		ll x = F(a, b, c, mid);
		ll y = F(a, b, c, mid-1);
		if(x>=k and y<k) return mid;
		if(x>k) u = mid-1;
		else l = mid+1;
	}
	return 0;
}

int main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin>>t;
	while(t--){
		int a, b, c;
		ll k;
		cin>>a>>b>>c>>k;
		cout<<solve(a, b, c, k)<<endl;
	}
}
