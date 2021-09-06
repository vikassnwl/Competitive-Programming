#include<bits/stdc++.h>
#define endl '\n'
#define mod 1000000007
#define ll long long
using namespace std;

// K can't be greater than 1023 because the max value of si(set element) can be 1023 and if we take k greater than 1023, let's take 1024 which has 11 bits in it's binary representation, the xor between 1023 and 1024 will result in a 11 bits number but the number(si) can't have more than 10 bits.
// 1024 -> 10000000000
// 1023 -> 01111111111
// 	  -------------
// xor  -> 11111111111 The result has 11 bits which violates our constraint. That's why k will lie between 1-1023(inclusive)

int main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		set<int> st;
		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			st.insert(x);
		}
		bool flag = true;
		for(int i=1; i<1024; i++){
			set<int> res;
			for(int x: st){
				res.insert(x^i);
			}
			if(st==res){
				cout<<i;
				flag = false;
				break;
			}
		}
		if(flag)
			cout<<-1;
		cout<<endl;
	}
}
