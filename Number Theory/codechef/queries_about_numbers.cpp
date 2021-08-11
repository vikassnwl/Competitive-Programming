#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;

unordered_map<ll, ll> mp;
ll total = 1;

void factorize(ll n){
	for(ll i=2; i*i<=n; i++){
		if(n%i==0){
			ll cnt = 0;
			while(n%i==0){
				cnt++;
				n /= i;
			}
			total *= cnt+1;
			mp[i] = cnt;
		}
	}
	if(n>1) total *= 2, mp[n] = 1;
}

int main(){	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll n, q;
	cin>>n>>q;
	factorize(n);
	while(q--){
		ll t, k;
		cin>>t>>k;
		if(t==1){
			ll res = 1;
			for(auto x: mp){
				ll cnt = 0;
				while(k%x.first==0){
					cnt++;
					k /= x.first;
				}
				res *= min(cnt, x.second)+1;
			}
			cout<<res<<endl;
		}
		else if(t==2){
			ll res = 1;
			for(auto x: mp){
				ll cnt = 0;
				while(k%x.first==0){
					cnt++;
					k /= x.first;
				}
				if(cnt>x.second){
					res = 0;
					break;
				}
				res *= x.second-cnt+1;
			}
			if(k>1) res = 0;
			cout<<res<<endl;
		}
		else{
			ll res = 1;
			for(auto x: mp){
				ll cnt = 0;
				while(k%x.first==0){
					cnt++;
					k /= x.first;
				}
				if(cnt>x.second){
					res = 0;
					break;
				}
				res *= x.second-cnt+1;
			}
			if(k>1) res = 0;
			cout<<total-res<<endl;

		}
	}
}
