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

pair<int, int> arr[3001];
int n;
int dp[3001][3001];
const int INF = 1000000000000000;

int getAns(int pos, int pre){
	if(pos>n) return 0;
	if(dp[pos][pre]!=-INF) return dp[pos][pre];
	//pin it
	int x = arr[pos].second+getAns(pos+1, pos);

	//leave it
	int y = arr[pos].first-arr[pre].first+getAns(pos+1, pre);

	return dp[pos][pre] = min(x, y);
}

void solve(){
	cin>>n;
	for(int i=1; i<=n; i++) cin>>arr[i].first>>arr[i].second;
	sort(arr+1, arr+n+1);
	for(int i=0; i<=n; i++){
		for(int j=0; j<=n; j++){
			dp[i][j] = -INF;
		}
	}
	int ans = getAns(2, 1)+arr[1].second;
	cout<<ans;
}

signed main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
}
