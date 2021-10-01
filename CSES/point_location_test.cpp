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

struct Point{
	int x, y;
};

void solve(){
	Point p1, p2, p3;
	cin>>p1.x>>p1.y>>p2.x>>p2.y>>p3.x>>p3.y;
	int val = (p2.y-p1.y)*(p3.x-p2.x)-(p3.y-p2.y)*(p2.x-p1.x);
	if(val==0) cout<<"TOUCH"<<endl;
	else if(val<0) cout<<"LEFT"<<endl;
	else cout<<"RIGHT"<<endl;
}

signed main(){	
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin>>t;
	while(t--)
		solve();
}
