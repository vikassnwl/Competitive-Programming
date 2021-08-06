#include<bits/stdc++.h>
using namespace std;

int pre[100005] , suff[100005];
int ar[100001];

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b , a % b);
}

int main(){
	int t , q , n ,l , r;
	cin>>t;
	while(t--){
		cin>>n>>q;
		for(int i=1; i<=n; i++)
			cin>>ar[i];
		pre[0] = suff[n+1] = 0;
		for(int i=1; i<=n; i++)	
			pre[i] = gcd(pre[i-1] , ar[i]);
		for(int i=n;i>=1;i--)
			suff[i] = gcd(ar[i] , suff[i+1]);
		while(q--){
			cin>>l>>r;
			cout<<gcd(pre[l-1] , suff[r+1])<<endl;
		}
	}
}
