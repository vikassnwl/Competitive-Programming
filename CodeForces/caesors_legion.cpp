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
#define mod 100000000
#define ll long long

int limit_f, limit_h;
int dp[101][101][11][11];
int getAns(int f, int h, int k1, int k2){
	if(f+h==0) return 1;
	if(dp[f][h][k1][k2]!=-1) return dp[f][h][k1][k2];
	int x = 0;
	if(f>0&&k1>0) x = getAns(f-1, h, k1-1, limit_h);
	int y = 0;
	if(h>0&&k2>0) y = getAns(f, h-1, limit_f, k2-1);
	return dp[f][h][k1][k2] = (x+y)%mod;
}

void solve(){
	memset(dp, -1, sizeof dp);
	int n1, n2;
	cin>>n1>>n2>>limit_f>>limit_h;
	cout<<getAns(n1, n2, limit_f, limit_h);
}

int main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}
