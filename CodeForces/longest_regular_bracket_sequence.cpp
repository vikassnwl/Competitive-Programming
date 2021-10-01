#include<bits/stdc++.h>
using namespace std;

//================PBDS==================
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset =
tree<T, null_type, less<T>, rb_tree_tag,
tree_order_statistics_node_update>;
//======================================

#define endl '\n'
#define mod 1000000007
#define int long long

int E[1000001], S[1000001], F[1000001];

void solve(){
	string st;
	int mx = 0;
	stack<int> stk;
	cin>>st;

	for(int i=0; i<st.size(); i++){
		char ch = st[i];
		if(ch=='('){
			stk.push(i);
		}
		else{
			if(stk.empty()){
				S[i] = E[i] = -1;
			}
			else{
				int idx = stk.top();
				stk.pop();
				S[i] = E[i] = idx;
				if(idx>0 and st[idx-1]==')' and S[idx-1]>=0)
					E[i] = E[idx-1];
				int l = i-E[i]+1;
				F[l]++;
				mx = max(mx, l);
			}
		}
	}
	F[0] = 1;
	cout<<mx<<" "<<F[mx];
}

signed main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}
