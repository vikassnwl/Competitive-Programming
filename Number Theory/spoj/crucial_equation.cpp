#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

int gcd(int a, int b){
	if(b==0) return a;
	return gcd(b, a%b);
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin>>t;
	int i = 1;
	while(t--){
		int a, b, c;
		cin>>a>>b>>c;
		if(a==0 and b==0){
			if(c==0) cout<<"Case "<<i<<": "<<"Yes"<<endl;
			else cout<<"Case "<<i<<": "<<"No"<<endl;
		}
		else{
			if(c%gcd(a, b)==0) cout<<"Case "<<i<<": "<<"Yes"<<endl;
			else cout<<"Case "<<i<<": "<<"No"<<endl;
		}
		i++;
	}
}
